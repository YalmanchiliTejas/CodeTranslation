#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int point[5] = {0, 0, 60, 70, 80};
void get(int v[], int S){
  /*
  printf("%d: ", S);
  REP(i, 5) printf("%d ", v[i]);
  printf("->");
  */
  REP(i, 4){
    if(v[i] > 0){
      v[i] += S & 3;
      if(v[i] > 4) v[i] -= 4;
    }
    if(v[i + 1] > 0){
      v[i + 1] += S & 3;
      if(v[i + 1] > 4) v[i + 1] -= 4;
    }
    S >>= 2;
  }
  /*
  REP(i, 5) printf("%d ", v[i]);
  cout<<endl;
  */
}

int main(){
  int N;
  cin>>N;
  while(N--){
    int a[5][5];
    REP(i, 5)REP(j, 5){
      cin>>a[i][j];
    }
    int dp[5][256] = {}; //[5][4^5]
    int from[5][256] = {};
    REP(S, 256){
      int v[5]; 
      memcpy(v, a[0], sizeof(v));
      get(v, S);
      REP(i, 5) dp[0][S] += point[v[i]];
    }
    FOR(i, 1, 4){
      REP(FS, 256)REP(S, 256){
        int v[5]; 
        memcpy(v, a[i], sizeof(v));
        get(v, S);
        get(v, FS);
        int sum = 0;
        REP(j, 5) sum += point[v[j]];
        if(dp[i][S] < dp[i - 1][FS] + sum){
          dp[i][S] = dp[i - 1][FS] + sum;
          from[i][S] = FS;
        }
      }
    }
    int ans = 0;
    REP(S, 256){
      int v[5]; 
      memcpy(v, a[4], sizeof(v));
      get(v, S);
      int sum = 0;
      REP(j, 5) sum += point[v[j]];
      ans = max(ans, dp[3][S] + sum);
    }
    cout<<ans<<endl;
  }
  return 0;
}