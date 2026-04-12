#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll MOD = (1e+9)+7;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
ll mod_pow(ll x, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x%mod;
		x = x * x%mod;
		n >>= 1;
	}
	return res;
}
struct seg { int le, ri,num; ll hei; };
int main() {
	int n; cin >> n; ll h[100];
	rep(i, n) {
		cin >> h[i];
	}
	ll res = 1;
	if (n == 1) {
		cout << mod_pow(2, h[0], MOD) << endl; return 0;
	}
	rep(i, n) {
		if (i == 0) {
			if (h[0] > h[1]) {
				(res *= mod_pow(2, h[0] - h[1],MOD)) %= MOD;
				h[0] = h[1];
			}
		}
		else if (i == n - 1) {
			if (h[n - 2] < h[n - 1]) {
				(res *= mod_pow(2, h[n - 1] - h[n - 2],MOD)) %= MOD;
				h[n - 1] = h[n - 2];
			}
		}
		else {
			ll mh = max(h[i - 1], h[i + 1]);
			if (h[i] > mh) {
				(res *= mod_pow(2, h[i] - mh, MOD)) %= MOD;
				h[i] = mh;
			}
		}
	}
	seg a[1000];
	vector<int> G[1000];
	queue<seg> q; int sum = 0;
	q.push({ 0, n ,0,0 });
	while (!q.empty()) {
		seg nex = q.front(); q.pop();
		int le = nex.le; int ri = nex.ri; ll hei = nex.hei;
		int num = nex.num;
		ll mi = INF;
		Rep(i, le, ri) {
			mi = min(mi, h[i]);
		}
		a[num] = { le,ri,0,mi - hei };
		int now = le;
		Rep(i, le, ri) {
			if (mi == h[i]) {
				if (i - now > 0) {
					sum++;
					G[num].push_back(sum);
					q.push({ now, i, sum, mi });
				}
				now = i + 1;
			}
		}
		if (ri-now>0) {
			sum++;
			G[num].push_back(sum);
			q.push({ now,ri,sum,mi });
		}
	}
	LP dp[1000];
	per(i, sum+1) {
		int len = G[i].size();
		ll he = a[i].hei;
		int le = a[i].le; int ri = a[i].ri;
		if (len == 0) {
			dp[i].first = mod_pow(2, he, MOD);
			dp[i].second = mod_pow(2, ri - le, MOD);
			(dp[i].second += dp[i].first) %= MOD;
			(dp[i].second += MOD - (ll)2) %= MOD;
		}
		else {
			ll nex1 = mod_pow(2, he, MOD);
			int wei = ri - le;
			rep(j, len) {
				seg nod = a[G[i][j]];
				wei -= (nod.ri - nod.le);
			}
			ll nex2 = mod_pow(2, wei, MOD);
			rep(j, len) {
				int v = G[i][j];
				(nex1 *= dp[v].first) %= MOD;
				(nex2 *= (dp[v].first + dp[v].second) % MOD) %= MOD;
			}
			ll cnex = mod_pow(2, he, MOD);
			(cnex += MOD - (ll)2) %= MOD;
			rep(j, len) {
				int v = G[i][j];
				(cnex *= dp[v].first) %= MOD;
			}
			(nex2 += cnex) %= MOD;
			dp[i] = { nex1,nex2 };
		}
	}
	cout << res * dp[0].second % MOD << endl;
	return 0;
}