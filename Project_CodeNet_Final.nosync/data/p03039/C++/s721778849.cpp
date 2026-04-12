#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

ll powmod(ll a,ll n,ll m) {
    if(n == 0)
        return 1;

    if(n % 2 ==0){
        ll r = powmod(a,n/2,m);
        return r*r % m;
    }

    return a*powmod(a,n-1,m)%m;
}

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

ll factmod(ll a,ll m) {
    ll s=1;
    while(a>0){
        s = s*a % m;
        a -= 1;
    }
    return s;
}

int main(){

  ll n,m,k;
  cin >> n>> m >> k;
  ll s=0,l;
  ll a,b,c;
  a=factmod(n*m-2,mod);
  b=modinv(factmod(k-2,mod),mod);
  c=modinv(factmod(n*m-k,mod),mod);
  for(int i=1;i<n;i++){
    l=1;
    l*=(n-i);
    l%=mod;
    l*=pow(m,2);
    l%=mod;
    l*=a;
    l%=mod;
    l*=b;
    l%=mod;
    l*=c;
    l%=mod;
    l*=i;
    l%=mod;
    s+=l;
    s%=mod;
  }

  for(int i=1;i<m;i++){
    l=1;
    l*=(m-i);
    l%=mod;
    l*=pow(n,2);
    l%=mod;
    l*=a;
    l%=mod;
    l*=b;
    l%=mod;
    l*=c;
    l%=mod;
    l*=i;
    l%=mod;
    s+=l;
    s%=mod;
  }

  cout << s << endl;

}