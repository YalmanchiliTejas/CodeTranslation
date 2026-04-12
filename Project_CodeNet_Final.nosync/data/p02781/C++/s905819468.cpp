#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
#define fi first
#define se second
#define pb push_back
char a[N];
int k,n;
LL dp[111][2][4];
LL dfs(int pos,int lim,int s){
  if(dp[pos][lim][s]!=-1)return dp[pos][lim][s];
  if(pos==n+1){
    if(s==k)return 1;
    return 0;
  }
  int r=lim?(a[pos]-'0'):9;
  LL ans=0;
  for(int i=0;i<=r;i++){
    if(!i){
      ans+=dfs(pos+1,lim&&(i==r),s);
    }else{
      if(s==k)break;
      ans+=dfs(pos+1,lim&&(i==r),s+1);
    }
  }
  dp[pos][lim][s]=ans;
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin>>a+1>>k;
  memset(dp,-1,sizeof dp);
  n=strlen(a+1);
  cout<<dfs(1,1,0)<<'\n';
  return 0;
}