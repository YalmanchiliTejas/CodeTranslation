#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>
#include <climits>
#include <functional>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<PII> VPI;
typedef vector<PLL> VPL;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pf push_front
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ub upper_bound
#define lb lower_bound

const int MAX=510000;
const int mod=1000000007;
ll fac[MAX],finv[MAX],inv[MAX];

ll modpow(ll a,ll n){
  ll res=1;
  while(n){
    if(n&1) res=res*a%mod;
    a=a*a%mod;
    n>>=1;
  }
  return res;
}

ll modinv(ll a){
  return modpow(a,mod-2);
}

void init(){
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  rep(i,MAX){
    if(i>1){
      fac[i]=fac[i-1]*i%mod;
      inv[i]=mod-inv[mod%i]*(mod/i)%mod;
      finv[i]=finv[i-1]*inv[i]%mod;
    }
  }
}

ll com(int n,int k){
  if(n<k) return 0;
  if(n<0||k<0) return 0;
  return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}

int main(){
  int N;
  cin>>N;
  VI A(N);
  rep(i,N) cin>>A[i];
  ll sum=0;
  rep(i,N) sum+=A[i];
  ll ans=0;
  rep(i,N) (ans+=(sum+mod-A[i])%mod*A[i]%mod)%=mod;
  cout<<ans*modinv(2)%mod<<endl;
}

