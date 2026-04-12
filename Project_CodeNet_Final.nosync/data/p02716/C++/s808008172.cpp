#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 202020;

int n, a[N];
ll pre[N], suf[N];
ll f[N], g[N];
//ll dp[N][N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n + 1) cin >> a[i];
//	rep(i, 0, n + 1) rep(j, 1, n + 1) dp[i][j] = -1e18;
//	rep(i, 1, n + 1) rep(j, 1, i + 1) {
//		dp[i][j] = dp[i - 1][j];
//		if(i - 2 >= 0) dp[i][j] = max(dp[i][j], dp[i - 2][j - 1] + a[i]);
//	}
//	de(dp[n][n / 2]);
//	return 0;
	rep(i, 1, n + 1) {
		pre[i] = a[i];
		if(i - 2 > 0) pre[i] += pre[i - 2];
	}
	per(i, 1, n + 1) {
		suf[i] = a[i];
		if(i + 2 <= n) suf[i] += suf[i + 2];
	}
	ll ans = -1e18;
	if(n & 1) {
		ans = max(suf[2], suf[3]);
		ans = max(ans, suf[1] - a[n]);
	//	de(ans);
		rep(i, 2, n - 1) {
			ll res = 0;
			if(i & 1) {
				res = max(pre[i - 1], pre[i - 2]);
				res += suf[i + 2];
			} else {
				res = pre[i - 1];
				res += max(suf[i + 2], suf[i + 3]);
			}
		//	de(res);
			ans = max(ans, res);
		}
		f[2] = -pre[2] + pre[1];
		rep(i, 4, n + 1) if(i % 2 == 0) f[i] = max(-pre[i] + pre[i - 1], f[i - 2]);
		g[n - 1] = -suf[n - 1] + suf[n];
		per(i, 2, n - 1) if(i % 2 == 0) g[i] = max(-suf[i] + suf[i + 1], g[i + 2]);
		rep(i, 2, n + 1) if(i % 2 == 0) ans = max(ans, pre[n - 1] + f[i] + g[i]);
	} else {
		ans = max(pre[n], pre[n - 1]);
		rep(i, 1, n) if(i % 2 == 0) ans = max(ans, pre[i - 1] + suf[i + 2]);
		
	}
	cout << ans << endl;
	return 0;
}
