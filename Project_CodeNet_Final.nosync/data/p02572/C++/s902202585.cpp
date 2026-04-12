#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
  int n,a[200000];
  ll sum=0,b[200000];
  cin>>n;
  a[0]=0;
  b[0]=0;
  ll mod=1e9+7;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    b[i]=(a[i-1]+b[i-1])%mod;
  }
  for(int i=1;i<=n;i++){
    sum=(sum+a[i]*b[i]%mod)%mod;
  }
  cout<<sum<<endl;
  return 0;
}