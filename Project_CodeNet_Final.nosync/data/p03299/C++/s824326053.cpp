#include "bits/stdc++.h"
using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl


typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define rrep1(i,n) for(int i=n;i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(all(v)), v.end())
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
const ll inf = 1000000001;
const ll INF = 2e18;
const ll MOD = 1000000007;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair


vii G(10000);
vl dp1(10000), dp2(10000);
vector<pll> rect(10000);
vl h(110);
int cnt = 0;
int n;
set<ll> st;

ll mod_pow(ll x, ll p, ll M = MOD) {
	ll a = 1;
	while (p) {
		if (p % 2)
			a = a * x%M;
		x = x * x%M;
		p /= 2;
	}
	return a;
}


void dfs(ll now_h, int left, int right, int parent) {
	if (left == right) {
		return;
	}
	int idx = cnt++;
	if (parent != -1) {
		G[parent].push_back(idx);
	}
	ll nex_h = *st.lower_bound(now_h + 1);
	rect[idx] = pll(nex_h - now_h, right - left);
	REP (i, left, right) {
		if (h[i] == nex_h) {
			dfs(nex_h, left, i, idx);
			left = i + 1;
		}
	}
	dfs(nex_h, left, right, idx);
}

void dp(int now) {
	ll res1 = 1, res2 = 1;
	ll x = rect[now].first, w = rect[now].second;
	rep(i, G[now].size()) {
		dp(G[now][i]);
		res1 = res1 * dp1[G[now][i]] % MOD;
		res2 = res2 * ((dp1[G[now][i]] + dp2[G[now][i]]) % MOD) % MOD;
		w -= rect[G[now][i]].second;
	}
	dp1[now] = res1 * mod_pow(2, x) % MOD;
	dp2[now] = (mod_pow(2, w) * res2 % MOD + (mod_pow(2, x) - 2) % MOD * res1 % MOD) % MOD;
}

int main() {
	cin >> n;
	rep(i, n) {
		cin >> h[i];
		st.insert(h[i]);
	}
	dfs(0, 0, n, -1);
	dp(0);
	cout << dp2[0] << endl;
}