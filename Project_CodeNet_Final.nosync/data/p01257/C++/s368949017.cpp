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

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main(){
  int N, M;
  while(cin >> N >> M && N){
    vector<int> coin(N);
    REP(i, N) cin >> coin[i];
    vector<int> v(1 << N);
    REP(S, 1 << N) REP(i, N) if(S >> i & 1) v[S] += coin[i];
    vector<int> dp(M + 1, INF);
    dp[0] = 0;
    for(int i = 1; i <= M; i++){
      for(int j = 0; j < v.size(); j++){
        if(i - v[j] >= 0){
          dp[i] = min(dp[i], dp[i - v[j]] + 1);
        }
      }
    }
    cout << dp[M] << endl;
  }
  return 0;
}