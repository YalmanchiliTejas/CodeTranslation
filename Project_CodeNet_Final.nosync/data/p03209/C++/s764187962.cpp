#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define rep(i,n) for (int i = (0); i < (n); ++i)
#define rng(x) (x).begin(),(x).end()
#define rrng(x) (x).rbegin(),(x).rend()
#define debug(x) cout << #x << " = " << (x) << endl;
#define SUM(x) accumulate(rng(x),0)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define uni(x) x.erase(unique(rng(x)),x.end())
#define SP << " " <<
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int mod = 1000000007;
const double EPS = 1e-9;
const int INF = 1<<30;
const ll INFLL = 1LL<<60;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
//cout << fixed << setprecision(10);

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int NMAX = 50;
ll a[NMAX+1], p[NMAX+1];

ll rec(int N, ll X) {
  if (N == 0) return 1;
  if (X == 1) return 0;
  else if (X <= 1 + a[N-1]) return rec(N-1, X-1);
  else if (X == 2 + a[N-1]) return p[N-1] + 1;
  else if (X <= 2 + 2*a[N-1]) return p[N-1] + 1 + rec(N-1, X-2-a[N-1]);
  else return 2*p[N-1] + 1;
}

int main () {
  int n;
  ll x;
  cin >> n >> x;

  a[0] = 1;
  p[0] = 1;
  for (int i = 1; i <= n; ++i) {
    a[i] = 2*a[i-1] + 3;
    p[i] = 2*p[i-1] + 1;
  }

  cout << rec(n, x) << endl;
  return 0;
}