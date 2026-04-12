#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PI;
typedef pair<LL, LL> PLL;
const LL MOD = 1000000007LL;
const int inf = 1e9;
const LL INF = 1e18;
int main() {
	int N, K;
	cin >> N >> K;
	if (K == 0) {
		cout << (LL)N*N << endl;
		return 0;
	}
	LL ans = 0;
	for (int b = K + 1; b <= N; b++) {
		int n = (N + b - K) / b;
		int m = (N + 1) / b;
		int r1 = (N + b - K) % b;
		int r2 = (N + 1) % b;
		if (n == m) {
			ans += (LL)(r1 - r2 + 1)*n;
		}
		else {
			ans += (LL)(r1 + 1)*n;
			ans += (LL)(b - r2)*m;
		}
	}
	cout << ans << endl;
}