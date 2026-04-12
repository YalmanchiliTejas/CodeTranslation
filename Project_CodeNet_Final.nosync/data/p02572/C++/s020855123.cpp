#include <iostream>
#include <bits/stdc++.h>

#define rep(i,z) for(int i = 0; i<(int)(z); i++)
#define rep1(i,z) for(int i = 1; i<=(int)(z); i++)
 
using namespace std;

typedef long long ll;
const ll MOD=1e9+7;
using pear = pair<int,int>;

int main(){
  int n; cin>>n;
  ll a[n], ans=0,sum[n-1];
  rep(i,n){
    cin>>a[i];
    a[i]%=MOD;
  }
  sum[n-2]=a[n-1];
  for(int i=n-3;i>=0;i--) sum[i]=(sum[i+1]%MOD+a[i+1]%MOD)%MOD;
  for(int i = 0;i <n-1;i++){
    ans+= a[i]*sum[i]%MOD;
    ans%=MOD;
  }
  cout<<ans<<endl;
}