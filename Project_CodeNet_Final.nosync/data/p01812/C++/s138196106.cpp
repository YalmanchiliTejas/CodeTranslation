#include<bits/stdc++.h>
#define INF (1e9)
#define N 105
#define M 16
using namespace std;
typedef pair<int,int> P;
int n,m,k,d[M],G[N][N],dp[(1<<M)];
map<int,int> to;

int bfs(){
  queue<P> q;
  fill(dp,dp+(1<<M),INF);
  dp[0]=0;
  q.push(P(0,0));
  while(!q.empty()){
    P t=q.front(); q.pop();
    int cost=t.first,node=t.second;
    if(node==(1<<m)-1)return cost;
    if(dp[node]<cost)continue;
    for(int i=0;i<k;i++){
      int next=(1<<m)-1;
      for(int j=0;j<m;j++)
	if(!(node&(1<<j))&&to.count(G[d[j]][i]))
	  next=next&~(1<<to[G[d[j]][i]]);
      if(dp[next]>cost+1){
	dp[next]=cost+1;
	q.push(P(dp[next],next));
      }
    }
  }
}

int main(){
  cin>>n>>m>>k;
  for(int i=0;i<m;i++){
    cin>>d[i]; d[i]--;
    to[d[i]]=i;
  }
  for(int i=0;i<n;i++)
    for(int j=0;j<k;j++){
      cin>>G[i][j];
      G[i][j]--;
    }
  cout<<bfs()<<endl;
  return 0;
}