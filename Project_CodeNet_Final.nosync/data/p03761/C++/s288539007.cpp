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

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main () {
  int n;
  cin >> n;

  vi cnt_min(26,INF);
  rep(i,n) {
    string s;
    cin >> s;
    vi cnt(26,0);
    rep(j,sz(s)) {
      //DEBUG(s[j]-'a');
      cnt[s[j]-'a']++;
    }
    rep(j,26) {
      cnt_min[j] = min(cnt_min[j],cnt[j]);
    }
  }

  //rep(i,26) {
  //  cout << i << " :" << cnt_min[i] << endl;
  //}


  rep(i,26) {
    rep(j,cnt_min[i]) {
      putchar('a'+i);
    }
  }
  printf("\n");
}