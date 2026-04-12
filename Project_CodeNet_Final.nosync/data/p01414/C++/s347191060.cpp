#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(),(c).end()
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define MINF(a) memset(a,0x3f,sizeof(a))
#define POW(n) (1LL<<(n))
#define IN(i,a,b) (a <= i && i <= b)
using namespace std;
template <typename T> inline bool CHMIN(T& a,T b) { if(a>b) { a=b; return 1; } return 0; }
template <typename T> inline bool CHMAX(T& a,T b) { if(a<b) { a=b; return 1; } return 0; }
template <typename T> inline void SORT(T& a) { sort(ALL(a)); }
template <typename T> inline void REV(T& a) { reverse(ALL(a)); }
template <typename T> inline void UNI(T& a) { sort(ALL(a)); a.erase(unique(ALL(a)),a.end()); }
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-10;
/* ---------------------------------------------------------------------------------------------------- */

int N;
int H[20],W[20];
string S[5];
int can[5][5][5][5];
int bit[5][5][5][5][5];
int fil[5][5][5][5];
string ord = "RGB";
int dis[POW(16)+10];

int calc(int x) {
  if (IN(x,0,3)) return x;
  if (x < 0) return 0;
  return 3;
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  cin >> N;
  REP(i,N) cin >> H[i] >> W[i];
  REP(i,4) cin >> S[i];
  REP(k,N) {
    for (int y = -3; y <= 3; y++) {
      for (int x = -3; x <= 3; x++) {
        int L = calc(x);
        int R = calc(x+W[k]-1);
        int U = calc(y);
        int D = calc(y+H[k]-1);
        can[U][L][D][R] = 1;
        REP(c,3) {
          int tmp = 0;
          REP(i,H[k]) REP(j,W[k]) {
            if (IN(y+i,0,3) && IN(x+j,0,3)) {
              if (S[y+i][x+j] == ord[c]) {
                tmp |= POW((y+i)*4+(x+j));
              }
            }
          }
          bit[U][L][D][R][c] = tmp;
        }
      }
    }
  }
  REP(i,4) REP(j,4) FOR(k,i,4) FOR(l,j,4) {
    REP(x,16) {
      int add = 0;
      if (x < i*4) add = 1;
      else if (x >= (k+1)*4) add = 1;
      else if (x%4 < j) add = 1;
      else if (x%4 > l) add = 1;
      if (add) fil[i][j][k][l] |= POW(x);
    }
  }
  MINF(dis);
  dis[0] = 0;
  queue<int> que;
  que.emplace(0);
  while (!que.empty()) {
    int mask = que.front(); que.pop();
    REP(i,4) REP(j,4) FOR(k,i,4) FOR(l,j,4) if (can[i][j][k][l]) {
      REP(c,3) {
        int nmask = (mask & fil[i][j][k][l]) | bit[i][j][k][l][c];
        if (dis[nmask] == INF) {
          dis[nmask] = dis[mask] + 1;
          que.emplace(nmask);
        }
      }
    }
  }
  cout << dis[POW(16)-1] << endl;

  return 0;
}
