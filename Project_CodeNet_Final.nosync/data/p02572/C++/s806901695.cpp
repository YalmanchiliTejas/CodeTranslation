#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
int main(){
ll n,m;
  cin>>n;
  m=1e9+7;
  ll a[n],s=0;
  for(int i=0;i<n;i++){
  cin>>a[i];
    s+=(a[i]%m);
  }
ll ans=0;
  for(int i=0;i<n;i++){
  s-=a[i];
    ans= (ans%m + ((s%m)*(a[i]%m)%m))%m;
  }
  cout<<ans;
}