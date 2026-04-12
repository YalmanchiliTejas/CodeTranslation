#include "bits/stdc++.h"

#define MOD 1000000007
#define rep(i, n) for(ll i=0; i < (n); i++)
#define ALL(v) v.begin(),v.end()

using namespace std;
typedef long long int ll;
typedef vector<ll> llvec;
typedef vector<double> dvec;
typedef pair<int, int> P;


ll mod(ll a, ll mod){
  ll res = a%mod;
  if(res<0)res=res + mod;
  return res;
}

ll modpow(ll a, ll n, ll mod){
  ll res=1;
  while(n>0){
    if(n&1) res=res*a%mod;
    a=a*a%mod;
    n>>=1;
  }
  return res;
}

ll modinv(ll a, ll mod){
  return modpow(a, mod-2, mod);
}

bool is_prime(ll n){
  ll i = 2;
  if(n==1)return false;
  if(n==2)return true;
  bool res = true;
  while(i*i <n){
    if(n%i==0){
      res = false;
    }
    i = i+1;
  }

  //if(i==1)res = false;
  if(n%i==0)res=false;
  return res;
}

ll num_bg(int n){
  if(n==0)return 1;
  return 2*num_bg(n-1)+3;
}
ll num_pt(int n){
  if(n==0)return 1;
  return 2*num_pt(n-1)+1;
}

ll ans(ll N, ll K){
  if(N>1){
    ll bg = num_bg(N-1);
    if(K==1){
      return 0;
    }else if(K<2+bg){
      return ans(N-1, K-1);
    }else if(K==2+bg){
      return ans(N-1, K-2)+1;
    }else if(K<3+2*bg){
      return ans(N-1, K-2-bg)+num_pt(N-1)+1;
    }else{
      return ans(N-1, K-3-bg)+num_pt(N-1)+1;
    }
  }
  if(N==1){
    ll result[]={0,1,2,3,3};
    //cout <<K <<" "<< result[K-1] << endl;
    return result[K-1];
  }
}

/******************************************
** A main function is start from here  ****
*******************************************/
int main(){
  ll N, K;
  cin >> N >> K;
  //cout << num_bg(N) << " " << num_pt(N)<<endl;
  cout << ans(N,K);
  return 0;
}
