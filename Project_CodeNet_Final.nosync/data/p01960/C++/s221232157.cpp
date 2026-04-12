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
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (1e+18) + 7;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-6;
const ld pi = acos(-1.0);
//typedef vector<vector<ll>> mat;
typedef vector<int> vec;

ll mod_pow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%mod;
		a = a * a%mod; n >>= 1;
	}
	return res;
}

struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n%mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint &a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint &a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint &a, modint b) { a.n = ((ll)a.n*b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, int n) {
	if (n == 0)return modint(1);
	modint res = (a*a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

//const int max_n = 1 << 22;
//modint fact[max_n], factinv[max_n];
//void init_f() {
//	fact[0] = modint(1);
//	for (int i = 0; i < max_n - 1; i++) {
//		fact[i + 1] = fact[i] * modint(i + 1);
//	}
//	factinv[max_n - 1] = modint(1) / fact[max_n - 1];
//	for (int i = max_n - 2; i >= 0; i--) {
//		factinv[i] = factinv[i + 1] * modint(i + 1);
//	}
//}
//modint comb(int a, int b) {
//	if (a < 0 || b < 0 || a < b)return 0;
//	return fact[a] * factinv[b] * factinv[a - b];
//}

vector<int> G[1 << 17];

int subch[1 << 17];

void init_subch(int id, int fr) {
	subch[id] = 1;
	for (int to : G[id]) {
		if (to == fr)continue;
		init_subch(to, id);
		subch[id] += subch[to];
	}
}
int n,k;
int ans;
int dfs(int id, int fr) {
	vector<int> c0, c1;
	for (int to : G[id]) {
		if (to == fr)continue;
		int nex = dfs(to, id);
		if (subch[to] >= k) {
			c1.push_back(nex);
		}
		else {
			c0.push_back(nex);
		}
	}
	sort(all(c1), greater<int>());
	sort(all(c0), greater<int>());
	//merge two
	int ad = 0; if (n - subch[id] >= k)ad = 1;
	if (c1.size() >= 2) {
		ans = max(ans, ad + (int)c1.size() - 2 + c1[0] + c1[1]);
	}
	if (c1.size() >= 1 && c0.size() >= 1) {
		ans = max(ans, ad + (int)c1.size() - 1 + c1[0] + c0[0]);
	}
	if (c0.size() >= 2) {
		ans = max(ans, ad + (int)c1.size() + c0[0] + c0[1]);
	}
	//merge one
	if (c1.size() >= 1) {
		ans = max(ans, ad + (int)c1.size() - 1 + c1[0]);
	}
	if(c0.size() >= 1) {
		ans = max(ans, ad + (int)c1.size() + c0[0]);
	}

	int res = 0;
	//use previous
	if (c1.size() >= 1) {
		res = max(res, (int)c1.size() - 1 + c1[0]);
	}
	if (c0.size() >= 1) {
		res = max(res, (int)c1.size() + c0[0]);
	}
	//generate
	res = max(res,(int)c1.size());
	return res;
}
void solve() {
	cin >> n >> k;
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	init_subch(0, -1); dfs(0, -1);
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(12);
	//init_f();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}

