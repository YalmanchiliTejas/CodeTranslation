#include<bits/stdc++.h>
using namespace std;
using ll=long long;


int N, M;
int dp[(1<<8)+1][21];
vector<vector<bool>> G;

int rec(int bit, int v){
  if(dp[bit][v] != -1) return dp[bit][v];
  if(bit == (1<<v)) return dp[bit][v]=1;
  int prev_bit=bit & ~(1<<v);
  int res=0;
  for(int u=0;u<N;u++){
    if(!(prev_bit & (1<<u))) continue;
    rec(prev_bit, u);
    if(G[u][v]) res+=dp[prev_bit][u];
  }
  return dp[bit][v]=res;
}


int main(){
    cin >> N >> M;
    G.assign(N, vector<bool>(N, false));
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a][b]=G[b][a]=true;
    }
    for(int bit=0;bit<(1<<N);bit++){
        for(int v=0;v<N;v++){
            dp[bit][v]=-1;
        }
    }
    cout << rec((1<<N)-1, 0) << endl;
}