//besmellah
#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")

#define int long long
typedef pair <int, int> pii;
const int maxn = 3005, mod = 998244353;
int pd[maxn], dp[maxn], a[maxn];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	pd[0] = 1;
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = s; j >= 0; j--) {
			if (j >= a[i])
				pd[j] += pd[j - a[i]];
			pd[j] %= mod;
		}
		pd[0]++;
		for (int j = s; j >= 0; j--) {
			dp[j] += pd[j];
			dp[j] %= mod;
		}
	}
	cout << dp[s];
}
