#include "bits/stdc++.h"
using namespace std;
#define int long long
#define endl '\n'
int mod=1e9+7;
int mod2=998244353;
const int INF=1e9;

signed main(){
  int a,b,x;
  cin>>a>>b>>x;
  if(x<a){
    cout<<x%mod<<endl;
    return 0;
  }
  int n=(x-a)/(a-b)+1;
  n%=mod;
  a%=mod;
  b%=mod;
  x%=mod;
  int ans=x+(n*b)%mod;
  cout<<ans%mod<<endl;
}
