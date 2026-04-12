#include <bits/stdc++.h>
#define int long long
int dp[51][2000000];
using namespace std;

std::vector<int> v(51),w(51);
int dfs(int N,int X){
  if(X<2000000)if(dp[N][X]!=-1)return dp[N][X];
  if(N>=X)return 0;
  if(N==0&&X)return 1;
  if(X<v[N]/2+1){
    if(X<2000000)dp[N][X]=dfs(N-1,X-1);
    return dfs(N-1,X-1);
  }
  if(X==v[N]/2+1){
    if(X<2000000)dp[N][X]=dfs(N-1,X-1)+1;
    return dfs(N-1,X-1)+1;
  }
  if(X>v[N]/2+1){
    if(X<2000000)dp[N][X]=w[N-1]+1+dfs(N-1,X-v[N-1]-2);
    return w[N-1]+1+dfs(N-1,X-v[N-1]-2);
  }
}


signed main(){
  int N,X;
  cin>>N>>X;
  v[0]=1;w[0]=1;
  for(int i=1;i<51;i++)v[i]=v[i-1]*2+3;
  for(int i=1;i<51;i++)w[i]=w[i-1]*2+1;
  for(int i=0;i<51;i++)for(int j=0;j<2000000;j++)dp[i][j]=-1;
  cout<<dfs(N,X)<<endl;
}
