#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define rep(i,n) for (int i = (0); i < (n); ++i)
#define rng(x) (x).begin(),(x).end()
#define rrng(x) (x).rbegin(),(x).rend()
#define show(x) cout << #x << " = " << (x) << endl;
#define show2(x,y) cout << #x << " = " << (x) << ", " << #y << " = " << (y) << endl;
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
//cout << fixed << setprecision(10);

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main () {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i,n) cin >> s[i];
  
  vi cnt(26);
  for (char c = 'a'; c <= 'z'; ++c) {
    int mi = INF;
    rep(i,n) {
      int tmp = 0;
      rep(j,s[i].size()) {
        if (s[i][j] == c) tmp++;
      }
      mi = min(mi,tmp);
    }
    cnt[c-'a'] += mi;
  }

  string ans;
  for (char c = 'a'; c <= 'z'; ++c) {
    rep(_,cnt[c-'a']) {
      ans += c;
    }
  }

  cout << ans << endl;
  return 0;
}