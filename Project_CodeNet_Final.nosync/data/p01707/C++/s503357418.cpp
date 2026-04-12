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
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
ll dp[2001];
ll rdp[2001];
ll inv[2002];

ll mod_pow(ll x, ll n = mod - 2) {
	ll ret = 1;
	while (n) {
		if (n % 2)ret = ret * x%mod;
		x = x * x%mod; n >>= 1;
	}
	return ret;
}
void init() {
	rep1(i, 2001) {
		inv[i] = mod_pow(i);
	}
}
void solve() {
	init();
	int n; ll d; int x;
	while (cin >> n >> d >> x, n) {
		x--;
		fill(dp, dp + n, 0);
		fill(rdp, rdp + n + 1, 1);
		dp[0] = 1; rdp[0] = 0;
		vector<ll> s;
		rep(i, n) {
			rep(j, n+1) {
				dp[j] = rdp[j];
				if (j >= x)dp[j] -= rdp[j - x];
				if (dp[j] < 0) {
					dp[j] += mod;
				}
			}
			s.push_back(dp[n]);
			rep(j, n) {
				rdp[j + 1] = rdp[j] + dp[j];
				if (rdp[j + 1] >= mod)rdp[j + 1] -= mod;
			}
		}
		ll p = d%mod;
		ll ans = 0;
		rep(i, s.size()) {
			if (i + 1 > d)continue;
			//cout << p << " " << s[i] << endl;
			ans += p * s[i]%mod; ans %= mod;
			p = p * ((d - 1 - i)%mod) % mod;
			p = p * inv[i + 2] % mod;
			//cout << i<<" "<<p << endl;
		}
		cout << ans << endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}

