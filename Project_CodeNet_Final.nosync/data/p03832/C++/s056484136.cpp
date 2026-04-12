#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl

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
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = 1e18;
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair


const int MAXN = 3010;

vl fact(MAXN);
vl rfact(MAXN);

ll mod_pow(ll x, ll p, ll M = MOD) {
	ll a = 1;
	while (p) {
		if (p % 2)
			a = a*x%M;
		x = x*x%M;
		p /= 2;
	}
	return a;
}

ll mod_inverse(ll a, ll M = MOD) {
	return mod_pow(a, M - 2, M);
}

void set_fact(ll n, ll M = MOD) {
	fact[0] = fact[1] = rfact[0] = rfact[1] = 1;
	for (ll i = 2; i <= n; i++) {
		fact[i] = i * fact[i - 1] % M;
		rfact[i] = mod_inverse(fact[i], M);
	}
}

//http://drken1215.hatenablog.com/entry/2018/06/08/210000
//nが大きくfactが計算できないときのほかの計算方法について書いてある
ll nCr(ll n, ll r, ll M = MOD) {
  if (r > n) return 0;
  ll ret = fact[n];
  ret = (ret*rfact[r]) % M;
  ret = (ret*rfact[n - r]) % M;
  return ret;
}


int main() {
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  set_fact(n + 5);
  vll dp(b + 1, vl(n + 1));
  dp[a - 1][0] = 1;
  rep (i, b) {
    rep (j, n + 1) {
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j] %= MOD;
      for (int k = c; k <= d; k++) {
        if (j + (i + 1) * k > n) break;
        dp[i + 1][j + (i + 1)*k] += dp[i][j] * fact[n - j] % MOD * rfact[k] % MOD * rfact[(n - j) - k*(i + 1)] % MOD * mod_inverse(mod_pow(fact[i + 1], k)) % MOD;
        dp[i + 1][j + (i + 1) * k] %= MOD;
      }
    }
  }
  cout << dp[b][n] << endl;
}
