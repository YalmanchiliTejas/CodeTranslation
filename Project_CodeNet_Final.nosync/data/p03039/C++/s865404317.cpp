#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#define MOD 1000000007
#define mkp make_pair
typedef long long ll;
using namespace std;

ll N,M,K;

#define MAX_N 200020
ll inv[MAX_N+10],fac[MAX_N+10],ifac[MAX_N+10];

void setComb(){
  inv[0]=1;inv[1]=1;fac[1]=1;ifac[1]=1;fac[0]=1;ifac[0]=1;
  for(int i=2;i<MAX_N;i++){
    inv[i]=(-MOD/i)*inv[MOD%i]%MOD;
    fac[i]=fac[i-1]*i%MOD;
    ifac[i]=ifac[i-1]*inv[i]%MOD;
  }
  return;
}

ll comb(ll n,ll k){
  if(n<k||n<0||k<0) return 0;
  else return ((fac[n]*ifac[k]%MOD*ifac[n-k]%MOD+MOD)%MOD);
}

ll hcomb(ll n,ll r){
  if(n==0&&r==0) return 1;
  else if(n<0||r<0) return 0;
  else return comb(n+r-1,r);
}

int main(){
  cin>>N>>M>>K;

  ll ansx=0;
  for(ll i=1;i<=N;i++){
    ll tmp=i*(i-1)/2;
    //ll res=(N-i+1)*(N-i)/2;

    //ll po=(tmp+res)%MOD;
    ansx=(ansx+tmp)%MOD;
  }

  ll ansy=0;
  for(ll i=1;i<=M;i++){
    ll tmp=i*(i-1)/2;
    //ll res=(M-i+1)*(M-i)/2;

    //ll po=(tmp+res)%MOD;
    ansy=(ansy+tmp)%MOD;
  }

  //ansx=(ansx*(-MOD/2)%MOD);
  //ansy=(ansy*(-MOD/2)%MOD);

  ansx=ansx*M%MOD*M%MOD;
  ansy=ansy*N%MOD*N%MOD;

  ansx=(ansx+MOD)%MOD;
  ansy=(ansy+MOD)%MOD;

  ll ans=(ansx+ansy+MOD)%MOD;

  setComb();
  ll k=comb(N*M-2,K-2);

  ans=ans*k%MOD;
  cout<<ans<<endl;
  //cout<<(ansx+ansy+MOD)%MOD<<endl;


  return 0;
}
