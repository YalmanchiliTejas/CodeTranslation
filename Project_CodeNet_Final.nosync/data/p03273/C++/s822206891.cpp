#include <bits/stdc++.h>
#include<algorithm>
#include<math.h>
using namespace std;
 
template <class T> using V = vector<T>;
 
using ll = long long;
using db = double;
using st = string;
using ch = char;
using vll = V<ll>;
using vpll =V<pair<ll,ll>>;
using vst = V<st>;
using vdb = V<db>;
using vch = V<ch>;
 
 
#define FOR(i,a,b) for(ll i=(a);i<(ll)(b);i++)
#define rFOR(i,a,b) for(ll i=(a);i>(ll)(b);i--)
#define oFOR(i,a,b) for(ll i=(a);i<(ll)(b);i+=2)
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
 
 
ll combi(ll n,ll m) {
  ll ans=1;
  rFOR(i,n,n-m){
    ans*=i;
  }
  FOR(i,1,m+1){
    ans/=i;
  }
  return ans;
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
  ll h,w;
  	ci(h>>w);
  vst A(h);
  FOR(i,0,h){
    ci(A[i]);
  }
  st s;
  FOR(i,0,w){
    s+='.';
  }

  FOR(i,0,h){
    if(A[i]==s) continue;
    
    else{
    FOR(j,0,w){
      bool b=false;
      FOR(k,0,h){
        if(A[k][j]!='.'){
          b=true;
            break;
        }
      }
        if(b) cout<<A[i][j];
    }
    }
    co(" ")
  }
}