#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define RFOR(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(i,n) FOR(i,0,(n))
#define REPS(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) RFOR(i,0,(n))
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define DEBUG(x)  cout << #x << " = " << (x) << endl;
#define SORT(x) sort(ALL(x));
#define RSORT(x) sort(RALL(x));
#define SUM(x) accumulate(ALL(x),0);
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const ll mod = 1e9+7;
const int INF = (1<<30)-1;
const ll INFLL = (1LL<<62)-1;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
//cout << fixed << setprecision(10);

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

template<class T> inline int sgn(T n) { if (n > 0) return 1; else if (n < 0) return -1; else return 0; }

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int n, m;
const int MAX = 10;
vi to[MAX];

int main () {
  cin >> n >> m;
  rep(i,m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  
  vi v;
  rep(i,n-1) {
    v.push_back(i+1);
  }
  /*for (auto x : v) {
    cout << x << " " ;
  }
  cout << endl;*/

  int ans = 0;
  do {
    rep(i,n-1) {
      if (find(ALL(to[v[i]]),v[i+1])==to[v[i]].end()) break;
      if (i == n-2) ans++;
    }
  } while (next_permutation(ALL(v)));

  cout << ans << endl;
  return 0;
}