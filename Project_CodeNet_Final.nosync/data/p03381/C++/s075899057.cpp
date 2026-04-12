#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n,a[222222],b[222222];
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
  b[0]=0;
  sort(b,b+n+1);
  int c=b[n/2],d=b[n/2+1];
  int t=c+d;
  t/=2;
  for(int i=1;i<=n;i++){
    if(a[i]<=t)cout<<d<<endl;
    else cout<<c<<endl;
  }
  //cout<<c<<d<<endl;
  return 0;
}
