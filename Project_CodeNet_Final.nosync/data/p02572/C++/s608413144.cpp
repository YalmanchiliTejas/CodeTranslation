#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

ll modinv(ll a,ll m){
  ll b=m,u=1,v=0;
  while(b){
    ll t=a/b;
    a-=t*b; swap(a,b);
    u-=t*v; swap(u,v);
  }
  u%=m; 
  if(u<0) u+=m;
  return u;
}

int main(){
  int n;
  cin>>n;
  
  vector<ll> A(n);
  rep(i,n) cin>>A[i];
  
  ll sum=0,sum2=0;
  
  rep(i,n){
    sum=(sum+A[i])%MOD;
    sum2=(sum2+A[i]*A[i]%MOD)%MOD;
  }
  
  cout<<((sum*sum%MOD-sum2+MOD)%MOD)*modinv(2,MOD)%MOD<<endl;
  
  return 0;
}