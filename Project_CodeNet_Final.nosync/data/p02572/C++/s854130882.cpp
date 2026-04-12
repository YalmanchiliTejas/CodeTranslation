#include<bits/stdc++.h>
using namespace std;
typedef int64_t ll;
const ll MOD=(ll)1e9+7;

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
  ll n;
  cin>>n;
  ll a[n],sum=0;
  for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}
  sum%=MOD;
  sum=sum*sum;
  for(int i=0;i<n;i++){sum-=a[i]*a[i];sum%=MOD;}
  sum*=modinv(2,MOD);
  sum%=MOD;
  cout<<(sum>=0 ? sum : sum+MOD)<<endl;
}
