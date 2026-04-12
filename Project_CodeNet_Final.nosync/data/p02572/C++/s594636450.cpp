#include <bits/stdc++.h>
using namespace std;

#define rep(ver,n) rep2(ver,0,n)
#define rep2(ver,m,n) for(int ver=m;ver<(n);ver++)
#define loop while(true)
#define dup(x,y) (((x)+(y)-1)/(y))
#define all(v) (v).begin(), (v).end()
#define debug(x) std::cerr<<#x<<": "<<x<<"\n"
#define debug2(x,y) std::cerr<<#x<<": "<<x<<", "<<#y<<": "<<y<<"\n"
#define debug3(x,y,z) std::cerr<<#x<<": "<<x<<", "<<#y<<": "<<y<<", "<<#z<<": "<<z<<"\n"

typedef long long ll;
typedef pair<int, int> P;

int n;
ll a[300000]={};
ll sum=0;
ll mod=1000000007;
ll all_sum=0;
ll sqr_sum=0;

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main(){
  cin>>n;
  
  rep(i,n){
    cin>>a[i];
  }
  
  rep(i,n){
    all_sum+=a[i];
    sqr_sum+=a[i]*a[i];
    all_sum%=mod;
    sqr_sum%=mod;
  }
  
  ll ans=(all_sum*all_sum-sqr_sum);
  ans%=mod;
  ans*=modinv(2,mod);
  ans%=mod;
  
  cout<<ans;
  
  return 0;
}
