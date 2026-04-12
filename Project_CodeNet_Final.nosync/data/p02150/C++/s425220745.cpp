#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7;
const ll LINF=1e18;
using namespace std;
#define int long long

signed main(){
  int a,b,x;cin>>a>>b>>x;
  if(x<a){cout<<x%MOD<<endl;return 0;}
  int ans=0;
  x-=a;
  int z=x/(a-b);z%=MOD;int aa=a%MOD;
  ans+=z*aa;ans%=MOD;
  x%=(a-b);
  ans+=a;ans+=x;ans+=b;
  ans%=MOD;
  cout<<ans<<endl;
}

