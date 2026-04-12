#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
#define fi first
#define se second
#define pb push_back
#define wzh(x) cerr<<#x<<'='<<x<<endl;
int n,a[N];
const int mod=1e9+7;
int add(int x,int y){
  x+=y;
  if(x>=mod)x-=mod;
  return x;
}
int di(int x,int y){
  x-=y;
  if(x<0)x+=mod;
  return x;
}
int mul(int x,int y){
  return 1ll*x*y%mod;
}
int main() {
  ios::sync_with_stdio(false);
  int sum=0;
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i],sum=add(sum,a[i]);
  int ans=0;
  for(int i=1;i<=n;i++){
    sum=di(sum,a[i]);
    ans=add(ans,mul(a[i],sum));
  }
  cout<<ans<<'\n';
  return 0;
}