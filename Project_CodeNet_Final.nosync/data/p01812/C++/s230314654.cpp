#include <bits/stdc++.h>
using namespace std;
int main(){
  map<int,int> ma;
  int n,m,k;
  cin>>n>>m>>k;
  int d[m],u[101]={};
  for(int i=0;i<m;i++){cin>>d[i];d[i]--;ma[d[i]]=i,u[d[i]]=1;}
  vector<int>v[n];
  for(int i=0;i<n;i++)for(int j=0,x;j<k;j++){cin>>x;x--;v[i].push_back(x);}
  int dp[1<<m],INF=1<<29;
  fill(dp,dp+(1<<m),INF);
  dp[(1<<m)-1]=0;
  queue<int> que;
  que.push((1<<m)-1);
  while(!que.empty()){
    int t=que.front();que.pop();
    for(int j=0;j<k;j++){
      int r=0;
      for(int i=0;i<m;i++){
        if(t&(1<<i)){
          int x=v[d[i]][j];
          if(u[x])r|=1<<ma[x];
        }
      }
      if(dp[r]>dp[t]+1)dp[r]=dp[t]+1,que.push(r);
    }
  }
  cout<<dp[0]<<endl;
  return 0;
}
