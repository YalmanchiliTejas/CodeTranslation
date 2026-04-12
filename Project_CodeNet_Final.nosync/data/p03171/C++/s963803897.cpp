#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << " " <<
using namespace std;
using ll=long long;

const int MXN=3005;

int n,ok[MXN][MXN][2],a[MXN];
ll memo[MXN][MXN][2];

ll dp(int l,int r,int p){
  if(l>r)return 0;
  if(ok[l][r][p])return memo[l][r][p];
  ok[l][r][p]=1;
  if(p)return memo[l][r][p]=min(dp(l+1,r,0)-a[l],dp(l,r-1,0)-a[r]);
  return memo[l][r][p]=max(dp(l+1,r,1)+a[l],dp(l,r-1,1)+a[r]);
}

int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;++i)scanf("%d",a+i);
  printf("%lld\n",dp(1,n,0));
}
