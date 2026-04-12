#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
 
template <class T> using V = vector<T>;
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
 
const long long INF = 1LL << 60;
 
using ll = long long;
using db = double;
using st = string;
using ch = char;
using bl = bool;
using vll = V<ll>;
using vpll =V<pair<ll,ll>>;
using vst = V<st>;
using vdb = V<db>;
using vch = V<ch>;
using vbl = V<bl>;
 
 
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define rFOR(i,a,b) for(ll i=(a);i>(b);i--)
#define oFOR(i,a,b) for(ll i=(a);i<(b);i+=2)
#define bgn begin()
#define en end()
#define SORT(a) sort((a).bgn,(a).en)
#define REV(a) reverse((a).bgn,(a).en)
#define M(a,b) max(a,b)
#define rM(a,b) min(a,b)
#define fi first
#define se second
#define sz size()
#define gcd(a,b) __gcd(a,b)
#define co(a) cout<<a<<endl;
#define ci(a) cin>>a;
 

vll dp(100100);

ll sum(ll n) {
ll m=0;
  FOR(i,0,20){
    m+=n%10;
    n/=10;
    if(n==0){
      break;
    }
  }
  return m;
}
 
 
const int MAX = 510000;
const int MOD = 1000000007;
 
long long fac[MAX], finv[MAX], inv[MAX];
 
void Comuse() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
 
#define comuse Comuse()
 
ll combi(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
 
 
 
 
ll lcm(ll a,ll b){
  ll n;
  n=a/gcd(a,b)*b;
  return n;
}


 
/****************************************\
| Thank you for viewing my code:)        |
| Written by RedSpica a.k.a. RanseMirage |
| Twitter:@asakaakasaka                  | 
\****************************************/
 
 
signed main() {
  ll n,x;
    ci(n>>x);
  vll A(n+1);
  vll P(n+1);
  A[0]=1;
  P[0]=1;

  FOR(i,1,n+1){
    A[i]=2*A[i-1]+3;
    P[i]=2*P[i-1]+1;
  }

  ll ans=0;

  while(true){
    
    if(x==1&&n!=0){
      co(0+ans)
      break;
    }
    else if(x==1&&n==0){
      co(1+ans)
      break;
    }

    else if(1<x&&x<=A[n-1]+1){
      n--;
      x--;
    }

    else if(x==A[n-1]+2){
      co(P[n-1]+1+ans)
      break;
    }

    else if(A[n-1]+2<x&&x<=2*A[n-1]+2){
      ans+=P[n-1]+1;
      x-=A[n-1]+2;
      n--;
    }

    else{
      co(2*P[n-1]+1+ans)
      break;
    }

  }
}