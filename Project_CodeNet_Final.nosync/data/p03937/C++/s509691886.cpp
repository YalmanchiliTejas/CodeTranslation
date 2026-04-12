#include <bits/stdc++.h>
using namespace std;

// repetition
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

// container util
#define all(x) (x).begin(), (x).end()

// typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

// const value
// const ll MOD = 1e9 + 7;
// const int dx[] = {0,1,0,-1};//{0,0,1,1,1,-1,-1,-1};
// const int dy[] = {1,0,-1,0};//{1,-1,0,1,-1,0,1,-1};

// conversion
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
inline ll toLL(string s) {
  ll v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T> inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}

template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
  return a < b && (a = b, true);
}

template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
  return a > b && (a = b, true);
}
vector<string> s;
ll h, w;

bool dfs(int ci = 0, int cj = 0) {
  s[ci][cj] = 'o';
  if(ci == h - 1 && cj == w - 1)
    return true;
  int ni = ci;
  int nj = cj + 1;
  if(ni >= 0 && ni < h && nj >= 0 && nj < w && s[ni][nj] == '#') {
    return dfs(ni, nj);
  } else {
    ni = ci + 1;
    nj = cj;
    if(ni >= 0 && ni < h && nj >= 0 && nj < w && s[ni][nj] == '#') {
      return dfs(ni, nj);
    } else {
      return false;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> h >> w;
  s.resize(h);
  rep(i, h) { cin >> s[i]; }
  bool flag1 = dfs();
  rep(i, h) rep(j, w) {
    if(s[i][j] == '#')
      flag1 = false;
  }
  if(flag1)
    cout << "Possible" << endl;
  else
    cout << "Impossible" << endl;
  return 0;
}
