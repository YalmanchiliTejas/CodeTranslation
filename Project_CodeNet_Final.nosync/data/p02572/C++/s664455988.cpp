#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define mat vector<vec>

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

ll powmod(ll a,ll n,ll m) {
    if(n == 0)
        return 1;

    if(n % 2 ==0){
        ll r = powmod(a,n/2,m);
        return r*r % m;
    }

    return a*powmod(a,n-1,m)%m;
}

ll factmod(ll a,ll b,ll m) {
  if(a<b)return 0;
  ll s=1;
  while(a>=b){
    s = s*a % m;
    a -= 1;
  }
  return s;
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

ll combmod(ll a,ll b,ll m){
  if(b==0)return 1;
  ll c=factmod(a,a-b+1,m);
  ll d=modinv(factmod(b,1,m),m);
  ll e=(c*d)%m;
  return e;
}

void modsum(ll &a,ll b,ll m){
  a+=b;
  a%=m;
}

void modsub(ll &a,ll b,ll m){
  a-=b;
  a+=m;
  a%=m;
}

void modmul(ll &a,ll b,ll m){
  a*=b;
  a%=m;
}

void modquo(ll &a,ll b,ll m){
  a*=modinv(b,m);
  a%=m;
}

int main(){

  ll n;
  cin >> n;
  ll a[n];
  for(ll i=0;i<n;i++)cin >> a[i];

  ll ans=0;
  ll s=0;
  for(ll i=0;i<n;i++)modsum(s,a[i],mod);
  modmul(s,s,mod);
  for(ll i=0;i<n;i++)modsub(s,a[i]*a[i]%mod,mod);
  modquo(s,2,mod);
  cout << s << endl;


}