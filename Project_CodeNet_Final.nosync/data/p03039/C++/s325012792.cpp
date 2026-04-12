#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

typedef long long ll;
typedef vector <ll> v_ll;
typedef vector <vector <ll> > vv_ll;
typedef vector < pair <ll,ll> > vp_ll;
typedef pair <ll,ll> p_ll;

ll N,M,K,X;
v_ll C;
ll MOD;

ll mod_inv(ll x,ll n){
  x%=n;
  if (x<0) x+=n;
  ll y = x,z = n-2;
  ll ret=1;
  while (z>0){
    if(z%2==1){
      ret*=y;
      ret%=n;
    }
    y*=y;
    y%=n;
    z/=2;
  }
  return ret;
}

v_ll mod_nck(ll n,ll nm){
  v_ll nck(n+1,0);
  nck[0]=1;
  for (ll i=1;i<=n;i++){
    nck[i]=(nck[i-1]*(n+1-i))%nm;
    nck[i]*=mod_inv(i,nm);
    nck[i]%=nm;
  }
  return nck;
}

int main(){
  cin >> N >> M >> K;
  X=N*M;
  MOD=1000000007;
  C=mod_nck(X-2,MOD);
  ll N2=0,M2=0;
  for(ll i=1;i<=M-1;i++){
    M2+=(i*(M-i));
    M2%=MOD;
  }
  for(ll i=1;i<=N-1;i++){
    N2+=(i*(N-i));
    N2%=MOD;
  }
  N2*=M;N2%=MOD;
  N2*=M;N2%=MOD;
  M2*=N;M2%=MOD;
  M2*=N;M2%=MOD;

  ll ans=N2+M2;
  ans%=MOD;

  ans *= C[K-2];
  ans%=MOD;
  cout << ans << endl;
}
