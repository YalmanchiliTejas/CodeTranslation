#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define f first
#define s second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcount(n)

#define si(x) scanf("%d",&x);
#define sli(x) scanf("%ld",&x);
#define sll(x) scanf("%lld",&x);
#define slu(x) scanf("%lu",&x);
#define sllu(x) scanf("%llu",&x);
#define si2(x,y) si(x);si(y);
#define si3(x,y,z) si(x);si(y);si(z);
#define slli2(x,y) slli(x);slli(y);
#define slli3(x,y,z) slli(x);slli(y);slli(z);

#define pi(x) printf("%d",x);
#define pli(x) printf("%ld",x);
#define plli(x) printf("%lld",x);
#define plu(x) printf("%lu",x);
#define pllu(x) printf("llu",x);
#define pn printf("\n");
#define ps printf(" ");
#define pc(c) printf("%c",c);
typedef long long int  ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> void setmin(T& a, T val) {if (a > val) a = val;}
template<class T> void setmax(T& a, T val) {if (a < val) a = val;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}


set<pair<ll, int> > ss;
int n;
const int MAXN = 210000;
 
int m;
int s, t;
 
vector<pair<int, ll> > eds[MAXN];
 
void solve(int s, pair<ll, ll> *dd) {
	for (int i = 0; i < n; ++i)
		dd[i] = make_pair(LINF, 0);
	dd[s] = make_pair(0, 1);
	ss.clear();
	ss.insert(make_pair(dd[s].first, s));
	while (!ss.empty()) {
		int x = ss.begin()->second;
		ss.erase(ss.begin());
		for (auto e: eds[x]) {
			int u = e.first;
			if (dd[u].first > dd[x].first + e.second) {
				ss.erase(make_pair(dd[u].first, u));
				dd[u].first = dd[x].first + e.second;
				ss.insert(make_pair(dd[u].first, u));
				dd[u].second = 0;
			}
			if (dd[u].first == dd[x].first + e.second)
				dd[u].second = (dd[u].second + dd[x].second) % MOD;
		}
	}
}
 
 
pair<ll, ll> ds[MAXN];
pair<ll, ll> dt[MAXN];
 
vector<tuple<int, int, ll> > ed;
 
 
int main() {
	scanf("%d%d", &n, &m);
	scanf("%d%d", &s, &t);
	--s, --t;
	for (int i = 0; i < m; ++i) {
		int a, b;
		ll c;
		scanf("%d%d%lld", &a, &b, &c);
		--a, --b;
		eds[a].push_back(make_pair(b, c));
		eds[b].push_back(make_pair(a, c));
		ed.push_back(make_tuple(a, b, c));
		ed.push_back(make_tuple(b, a, c));
	}
	solve(s, ds);
	solve(t, dt);
	ll ans = ds[t].second * ds[t].second % MOD;
	for (int i = 0; i < n; ++i) {
		if (ds[i].first == dt[i].first && ds[i].first * 2 == ds[t].first) {
			ll go = ds[i].second * dt[i].second % MOD;
			ans = (ans - go * go % MOD + MOD) % MOD;
		}
	}
	for (int i = 0; i < ed.size(); ++i) {
		int a, b;
		ll c;
		tie(a, b, c) = ed[i];
		if (c + ds[a].first + dt[b].first == ds[t].first) {
			if (ds[a].first * 2 < ds[t].first && dt[b].first * 2 < ds[t].first) {
				ll go = ds[a].second * dt[b].second % MOD;
				ans = (ans - go * go % MOD + MOD) % MOD;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
 
