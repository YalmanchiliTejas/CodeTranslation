#include<bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
#define int long long
int dp[3003][3003][2];
int n,a[3003];

int dfs(int l,int r,int t){
  if(l>r)return 0;
  if(dp[l][r][t]!=-1e16)return dp[l][r][t];
  if(t==0){
    int res=-1e15;
    res=max(res,dfs(l+1,r,1)+a[l]);
    res=max(res,dfs(l,r-1,1)+a[r]);
    return dp[l][r][t]=res;
  }
  else{
    int res=1e15;
    res=min(res,dfs(l+1,r,0)-a[l]);
    res=min(res,dfs(l,r-1,0)-a[r]);
    return dp[l][r][t]=res;
  }
}

signed main(){
  r(i,3003)r(j,3003)r(k,2)dp[i][j][k]=-1e16;
  cin>>n;
  r(i,n) cin>>a[i];
  cout<<dfs(0,n-1,0)<<endl;
}