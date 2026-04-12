#include <iostream>
#include <vector>
using namespace std;
const int INF = 1001001001;

template<typename T> int LIS_leq(const vector<T> &v, int l, int r, const T inf) {
	vector<T> dp(r - l, inf);
	for (int i = l; i < r; i++) {
		*upper_bound(dp.begin(), dp.end(), v[i]) = v[i];
	}
	return lower_bound(dp.begin(), dp.end(), inf) - dp.begin();
}

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		A[i] = -A[i];
	}
	int ans = LIS_leq(A, 0, n, INF);
	cout << ans << endl;
	return 0;
}