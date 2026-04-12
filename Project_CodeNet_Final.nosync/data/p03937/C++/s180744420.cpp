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
#define YES()         printf("YES\n")
#define NO()          printf("NO\n")
#define Yes()         printf("Yes\n")
#define No()          printf("No\n")
#define in(a,x,b)     ((a) <= (x) && (x) < (b))

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

const int dxs[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
const int dys[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int H,W;
  cin >> H >> W;
  string A[H];
  REP(i,H) cin >> A[i];

  REP(y,H) {
    REP(x,W) {
      if (A[y][x] == '#') {
        if (in(0,y+1,H) && in(0,x+1,W) && A[y][x+1] == '#' && A[y+1][x] == '#'
          || in(0,y-1,H) && in(0,x-1,W) && A[y-1][x] == '#' && A[y][x-1] == '#') {
          cout << "Impossible" << endl;
          return 0;
        }
      }
    }
  }

  cout << "Possible" << endl;

  return 0;
}