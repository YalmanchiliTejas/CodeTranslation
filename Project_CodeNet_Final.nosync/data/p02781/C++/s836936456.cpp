#include "bits/stdc++.h"

#define MOD 1000000007
#define rep(i, n) for(ll i=0; i < (n); i++)
#define ALL(v) v.begin(),v.end()
#define DUMP(i, v)for(ll i=0;i<v.size();i++)cout<<v[i]<<" "

using namespace std;
typedef long long int ll;
typedef vector<ll> llvec;
typedef vector<double> dvec;
typedef pair<int, int> P;
struct Edge{ll from, to, cost;};

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

ll dp1[110][4];
ll dp2[110][4];
ll visited1[110][4];
ll visited2[110][4];
string S;
ll K;

ll dpf1(ll keta, ll knum){
  if(visited1[keta][knum]==1){
    return dp1[keta][knum];
  }else{
    visited1[keta][knum]=1;
    if(keta==1){
      if(knum==1)dp1[keta][knum]=9;
      if(knum==0)dp1[keta][knum]=1;
    }else{
      if(knum==0)dp1[keta][knum]=dpf1(keta-1, knum);
      if(knum>=1)dp1[keta][knum]=dpf1(keta-1, knum)+9*dpf1(keta-1, knum-1);
    }
    return dp1[keta][knum];
  }
}
ll dpf2(ll keta, ll knum){
  if(visited2[keta][knum]==1){
    return dp2[keta][knum];
  }else{
    visited2[keta][knum]=1;
    if(keta==1){
      if(knum==0)dp2[keta][knum]=1;
      if(knum==1)dp2[keta][knum]= S[keta-1] - '0';
    }else{
      if(knum==0)dp2[keta][knum]=dpf2(keta-1, knum);
      if(knum>=1){
        if(S[keta-1]=='0')dp2[keta][knum] = dpf2(keta-1, knum);
        else{
          dp2[keta][knum]=dpf1(keta-1, knum);
          dp2[keta][knum]+=(S[keta-1]-'0'-1)*dpf1(keta-1, knum-1);
          dp2[keta][knum]+=dpf2(keta-1, knum-1);
        }
      }
    }
    return dp2[keta][knum];
  }
}


/**************************************
** A main function starts from here  **
***************************************/
int main(){
  cin >> S;
  cin >> K;
  reverse(ALL(S));
  cout << dpf2(S.size(), K);
  return 0;
}
