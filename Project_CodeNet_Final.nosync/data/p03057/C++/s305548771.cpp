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
typedef double ld;
typedef complex<ld> Point;
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

struct SegT {
private:
	int sz; vector<ll> node;
	const ll init_c = 0;
public:
	SegT(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	ll f(ll a, ll b) {
		return (a + b)%mod;
	}
	void update(int k, ll a) {
		k += sz - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	ll query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};

ll mod_pow(ll x, ll n) {
	ll ret = 1;
	while (n) {
		if (n % 2)ret = ret * x%mod;
		x = x * x%mod; n >>= 1;
	}
	return ret;
}
ll dp[1 << 18][2][2];
void solve() {
	int n, m; cin >> n >> m;
	string s; cin >> s;
	if (s[0] == 'B') {
		rep(i, m) {
			if (s[i] == 'B')s[i] = 'R';
			else s[i] = 'B';
		}
	}
	vector<int> v;
	rep(i, m) {
		int le = i;
		while (i + 1 < m&&s[i + 1] == s[i])i++;
		v.push_back(i - le + 1);
	}
	if (v.size() == 1) {
		dp[0][0][0] = 1;
		dp[0][1][1] = 1;
		rep(i, n - 1) {
			rep(j, 2) {
				(dp[i + 1][0][j] += dp[i][0][j] + dp[i][1][j]) %= mod;
				dp[i + 1][1][j] += dp[i][0][j];
			}
		}
		ll ans = dp[n - 1][0][0] + dp[n - 1][1][0] + dp[n - 1][0][1];
		cout << ans % mod << endl; return;
	}
	if (n % 2) {
		cout << 0 << endl; return;
	}
	int d = n / 2;
	int x = v[0] / 2 + 1;
	for (int i = 0; i < v.size(); i += 2) {
		if (i + 1 == v.size())break;
		if (v[i] % 2) {
			x = min(x, v[i] / 2 + 1);
		}
	}
	if (x >= d) {
		ll ans = mod_pow(2, d) - 1;
		ans = ans * 2;
		ans = (ans + mod) % mod;
		cout << ans << endl;
	}
	else {
		SegT dp(d + 1);
		dp.update(0, 1);
		rep1(i, d - 1) {
			int le = i - x;
			le = max(le, 0);
			ll nex = dp.query(le, i);
			dp.update(i, nex);
		}
		ll ans = 0;
		rep(i, x) {
			ll z = dp.query(d - x, d - i); ans += z;
			if (ans >= mod)ans -= mod;
		}
		ans = ans * 2 % mod;
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
