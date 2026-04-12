#include <iostream>
#include <vector>
using namespace std;
const int INF = 1001001001;

template<typename T> int LIS_leq(const vector<T> &v, const T inf) {
	vector<T> dp(v.size(), inf);
	for (const T &e : v) {
		*upper_bound(dp.begin(), dp.end(), e) = e;
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
	int ans = LIS_leq(A, INF);
	cout << ans << endl;
	return 0;
}