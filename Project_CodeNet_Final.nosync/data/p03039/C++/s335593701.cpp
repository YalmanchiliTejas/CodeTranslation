#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repeat(i,s,n) for(int (i)=s; (i)<(n); (i)++)
#define revrep(i,n) for(int (i)=(n)-1;i>=0; i--)

ll modpow(ll b, ll e, ll p) {
  if(e==0) return 1;
  if(e%2==0) {
    ll t = modpow(b,e/2,p);
    return (t*t)%p;
  }
  return (b*modpow(b,e-1,p))%p;
}

ll modinv(ll n, ll p) {
  return modpow(n,p-2,p);
}

ll modcomb(ll n, ll k, ll p) { // O(k)
  ll ans=1;
  for(ll i=n; i>=n-k+1; i--) {
    ans*=i;
    ans%=p;
  }
  for(ll i=1; i<=k; i++) {
    ans*=modinv(i,p);
    ans%=p;
  }
  return ans;
}

const ll p = 1e9+7;

ll f(ll n) {
  ll ans=modpow(n,3,p)-n%p;
  ans+=p;
  ans%=p;
  ans*=modinv(2*3,p);
  ans%=p;
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<setprecision(std::numeric_limits<float>::max_digits10);
  cout<<fixed;
  ll n,m,k;
  cin>>n>>m>>k;
  ll ans=0;
  ans+=(((m*m)%p)*f(n))%p;
  ans%=p;
  ans+=(((n*n)%p)*f(m))%p;
  ans%=p;
  ans*=modcomb(n*m-2,k-2,p);
  ans%=p;
  cout << ans << endl;
  return 0;
}
