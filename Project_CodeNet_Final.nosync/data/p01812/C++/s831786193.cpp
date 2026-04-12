#include<bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
int n,m,k,t1;
int dp[1<<16],t[101],a[101][101],d[101];
int main(){
  memset(dp,-1,sizeof(dp));
  memset(t,-1,sizeof(t));
  cin>>n>>m>>k;
  r(i,m){
    cin>>d[i];
    d[i]--;
    t[d[i]]=i;
  }
  r(i,n)r(j,k)
    cin>>t1,
    a[i][j]=t1-1;

  queue<int>q;
  q.push((1<<m)-1);
  dp[(1<<m)-1]=0;
  while(!q.empty()){
    int p=q.front();q.pop();
    if(!p){
      cout<<dp[0]<<endl;
      break;
    }
    r(i,k){
      int x=0;
      r(j,m)if((p>>j)&1)
        if(t[a[d[j]][i]]>=0)
          x|=(1<<t[a[d[j]][i]]);

      if(dp[x]<0){
        dp[x]=dp[p]+1;
        q.push(x);
      }

    }
  }
}