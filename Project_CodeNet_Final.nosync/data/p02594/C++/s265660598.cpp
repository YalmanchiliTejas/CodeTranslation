#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b)    for (int i=(a)  ;i<(b) ;i++)
#define RFOR(i,a,b)   for (int i=(b)-1;i>=(a);i--)
#define REP(i,n)      for (int i=0    ;i<(n) ;i++)
#define RREP(i,n)     for (int i=(n)-1;i>=0  ;i--)
#define EACH(i,a,b)   for (int i=(a)  ;i<=(b);i++)
#define REACH(i,a,b)  for (int i=(b)  ;i>=(a);i--)
#define ALL(a)        (a).begin(),  (a).end()
#define RALL(a)       (a).rbegin(), (a).rend()

const int MOD = 1e9 + 7;
const int INF = 1 << 29;
const double EPS = 1e-10;

using ll = long long;
using P = pair<int,int>;
template<class T = int> using V = vector<T>;

template<class T> bool inline chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool inline chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T = int> T inline input() { T x; cin >> x; return (x); }
template<class T> void inline print(T& x) { cout << x << '\n'; }
#define debug(x) cerr << #x << ": " << x << endl;

signed main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int X;
  cin >> X;

  cout << (X >= 30 ? "Yes" : "No") << endl;

  return 0;
}

