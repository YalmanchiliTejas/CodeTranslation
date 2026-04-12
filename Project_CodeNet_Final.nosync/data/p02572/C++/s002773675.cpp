#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200005;
const int mod=1e9+7;
ll a[N],suf[N];
int n;
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
  for(int i=n;i>=1;i--)suf[i]=(suf[i+1]+a[i])%mod;
  long long ans=0;
  for(int i=1;i<=n;i++){
    ans=(ans+a[i]*suf[i+1])%mod;
  }
  printf("%lld\n",ans);
  return 0;
} 
