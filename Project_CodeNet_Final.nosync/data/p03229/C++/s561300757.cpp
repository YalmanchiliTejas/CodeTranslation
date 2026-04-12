#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solve1(const vector<int>&A) {
	int i = 1, j = A.size() - 1;
	long long ans = 0, left = A[0], right = A[0];
	while (i <= j) {
		ans += abs(A[j] - left);
		left = A[j];
		j--;
		if (i > j) break;
		ans += abs(A[j] - right);
		right = A[j];
		j--;
		if (i > j) break;
		ans += abs(left - A[i]);
		left = A[i];
		i++;
		if (i > j) break;
		ans += abs(right - A[i]);
		right = A[i];
		i++;
	}
	return ans;
};

long long solve2(const vector<int>& A) {
	int i = 0, j = A.size() - 2;
	long long ans = 0, left = A.back(), right = A.back();
	while (i <= j) {
		ans += abs(left - A[i]);
		left = A[i];
		i++;
		if (i > j) break;
		ans += abs(right - A[i]);
		right = A[i];
		i++;
		if (i > j) break;
		ans += abs(A[j] - left);
		left = A[j];
		j--;
		if (i > j) break;
		ans += abs(A[j] - right);
		right = A[j];
		j--;
	}
	return ans;
};

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A.begin(), A.end());
	cout << max(solve1(A), solve2(A)) << endl;
}