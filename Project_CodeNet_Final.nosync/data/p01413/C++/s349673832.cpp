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

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;

int main(){
  int N, M, W, T;
  while(cin>>N>>M>>W>>T){
    map<string, int> product_id;
    string name[7];
    int weight[7] = {};
    int value[7] = {};
    REP(i, M){
      cin>>name[i]>>weight[i]>>value[i];
      product_id[name[i]] = i;
    }
    int L[8] = {}, X[8] = {}, Y[8] = {};
    string t_name[8][8];
    int t_value[8][8];
    REP(i, N){
      cin>>L[i]>>X[i]>>Y[i];
      REP(j, L[i]){
        cin>>t_name[i][j]>>t_value[i][j];
      }
    }

    int tsp[1<<8][8] = {};
    REP(i, 1<<8)REP(j, 8) tsp[i][j] = INF;
    REP(i, N) tsp[1<<i][i] = abs(X[i]) + abs(Y[i]);
    for(int S = 1; S < (1<<(N + 1)); S++){
      for(int from = 0; from < N; from++)if(S & (1<<from)){
        for(int to = 0; to <= N; to++)if(!(S & (1<<to))){
          tsp[S | (1<<to)][to] = min(tsp[S | (1<<to)][to], tsp[S][from] + abs(X[from] - X[to]) + abs(Y[from] - Y[to]));
        }
      }
    }

    int dist[1<<7] = {};
    for(int S = 1; S < 1<<N; S++) dist[S] = tsp[S | (1<<N)][N];

    int obtain[1<<7] = {};
    for(int S = 1; S < 1<<N; S++){
      int v[7];
      fill(v, v+7, INF);
      REP(i, N) if(S & (1<<i)){
        REP(j, L[i]) v[product_id[t_name[i][j]]] = min(v[product_id[t_name[i][j]]], t_value[i][j]);
      }
      int dp[10001] = {};
      for(int i = 0; i <= W; i++){
        for(int j = 0; j < M; j++){
          if(weight[j] + i <= W)dp[weight[j] + i] = max(dp[weight[j] + i], dp[i] + value[j] - v[j]);
        }
        obtain[S] = max(obtain[S], dp[i]);
      }
    }
    ll dp[10002] = {};
    ll ans = 0;
    for(int t = 0; t <= T; t++){
      for(int S = 1; S < 1<<N; S++){
        if(t + dist[S] <= T) dp[t + dist[S]] = max(dp[t + dist[S]], dp[t] + obtain[S]);
      }
      //printf("t:%d dp:%d\n", t, dp[t]);
      ans = max(ans, dp[t]);
    }
    cout<<ans<<endl;
  }
  return 0;
}