#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100],cnt[100],m,ans;
int main(){
  int n; cin>>n;
  ll s=0,x;
  for (int i=1; i<=n; ++i)
    cin>>a[i],s+=a[i];
  if (s>n*(n-1)){
    ans=x=s-n*(n-1);
    for (int i=1; i<=n; ++i)
      a[i]+=x;
    for (int i=1; i<=n; ++i){
      x-=a[i]/(n+1);
      a[i]%=(n+1);
    }
    ans-=x;
    for (int i=1; i<=n; ++i)
      a[i]-=x;
  }
  int flag=1;
  while(flag){
    m=flag=0;
    for (int i=1; i<=n; ++i)
      cnt[i]=a[i]/n,m+=cnt[i];
    for (int i=1; i<=n; ++i){
      a[i]-=cnt[i]*(n+1)-m;
      if (a[i]>=n) flag=1;
    }
    ans+=m;
  }
  cout<<ans;
  return 0;
}
