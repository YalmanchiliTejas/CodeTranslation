#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
int main(){
  int n,m,k,i,j,l,a,b,e,inf=1<<28;
  cin>>n>>m>>k;
  int dp[1<<m],d[n],c[k];
  map<int,int> r;
  vector<int> G[n][k];
  for(b=0;b<(1<<m);b++) dp[b]=inf;
  for(i=0;i<m;i++) cin>>d[i],r[--d[i]]=i;
  for(i=0;i<n;i++){
    for(j=0;j<k;j++){
      cin>>e;
      if(r.find(i)!=r.end()) G[e-1][j].push_back(i);
    }
  }
  queue<P> q;
  q.push(P(0,0));
  for(j=0;j<k;j++){
    c[j]=0;
    for(i=0;i<n;i++){
      if(r.find(i)!=r.end()) continue;
      for(l=0;l<G[i][j].size();l++)
	c[j]|=(1<<r[G[i][j][l]]);
    }
  }
  while(!q.empty()){
    a=q.front().first;b=q.front().second;q.pop();
    if(dp[b]<=a) continue;
    dp[b]=a;
    if(b==(1<<m)-1) break;
    for(j=0;j<k;j++){
      int o=0;
      for(i=0;i<m;i++){
	if(((b>>i)&1)==0) continue;
	for(l=0;l<G[d[i]][j].size();l++)
	  o|=(1<<r[G[d[i]][j][l]]);
      }
      if(a+1<dp[(o|c[j])]) q.push(P(a+1,(o|c[j])));
    }
  }
  cout << dp[(1<<m)-1] << endl;
  return 0;
}