#include <bits/stdc++.h>
using namespace std;
int num[101];
vector<int> G[101];
int n,m,K;
int mem[1<<16],used[1<<16];
int dfs(int bit){
  if(bit == 0) return 0;
  if(used[bit]++) return mem[bit];
  int &res = mem[bit] = 1e9;
  for(int k=0;k<K;k++){  
    int nbit = 0;
    for(int i=0;i<n;i++){
      int nx = G[i][k];
      if(num[i]<0||num[nx]<0||!(bit>>num[i]&1))continue;
      nbit |= (1<<num[nx]);
    }
    res = min(res,1+dfs(nbit));
  }
  return res;
}

int main(){

  cin>>n>>m>>K;
  memset(num,-1,sizeof(num));
  for(int i=0,a;i<m;i++)cin>>a,num[a-1]=i;
  
  for(int i=0;i<n;i++){
    G[i].resize(K);
    for(int j=0;j<K;j++)cin>>G[i][j],G[i][j]--;
  }
  cout<<dfs((1<<m)-1)<<endl;
  return 0;
}