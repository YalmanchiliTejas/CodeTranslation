#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<cstring>
#include<climits>
#include<sstream>
#include<deque>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<bitset>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)

using namespace std;

typedef long long ll;

#define MAX_V 9

int V,E;

bool edge[MAX_V][MAX_V];

ll dp[(1<<MAX_V)][MAX_V];

void compute() {
  dp[1][0] = 1;
  rep(viz,(1<<V)) {
    rep(cur,V) if( (viz>>cur) & 1 ) {
      rep(nex,V) if( !( (viz>>nex) & 1 ) ){
	if( !edge[cur][nex] ) continue;
	dp[viz|(1<<nex)][nex] += dp[viz][cur];
      }
    }
  }
  ll ans = 0;
  rep(i,V) ans += dp[(1<<V)-1][i];
  cout << ans << endl;
}

int main() {
  cin >> V >> E;
  rep(i,E) {
    int s,t;
    cin >> s >> t;
    --s, --t;
    edge[s][t] = edge[t][s] = true;
  }
  compute();
  return 0;
}


