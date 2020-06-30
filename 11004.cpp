#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& A, vector<int>& L, vector<int>& R) {
	A.clear();
	vector<int>::iterator it_L = L.begin();
	vector<int>::iterator it_R = R.begin();

	while (it_L != L.end() || it_R != R.end()) {
		if (it_L != L.end() && it_R != R.end()) {
			if (*it_L < *it_R) A.push_back(*it_L++);
			else A.push_back(*it_R++);
		}
		else if (it_L != L.end()) A.push_back(*it_L++);
		else A.push_back(*it_R++);
	}
}

void merge_sort(vector<int>& A) {
	int M = A.size() / 2;
	if (M != 0) {
		vector<int> L(A.begin(), A.begin() + M);
		merge_sort(L);
		vector<int> R(A.begin() + M, A.end());
		merge_sort(R);
		merge(A, L, R);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<int> A;

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		A.push_back(num);
	}

	merge_sort(A);
	cout << A[K - 1] << '\n';

	return 0;
}