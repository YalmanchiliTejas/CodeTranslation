#include<bits/stdc++.h>
#define rep(i,m) for(long long i=0; i<m; i++)
#define per(i,m) for(long long i=m-1; i>=0; i--)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define ROF(i,n,m) for(long long i=n-1; i>=m; i--)
#define all(x) (x).begin(),(x).end()
#define EPS (1e-7)
#define INF (1e18)
#define PI (acos(-1))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
typedef pair<ll, ll> LP;

ll POW(ll x,ll n){
  if(n==0)return 1;
  if(n%2==0)return POW(x*x%MOD,n/2);
  return x*POW(x,n-1)%MOD;
}

ll gcd(ll u, ll v) {
  ll r;
  while (0 != v) {
    r = u % v; u = v; v = r;
  }
  return u;
}
 
ll KAI(ll m)
{
  if(m<0) return 0;
  if(m==0) return 1;
  return m*KAI(m-1)%MOD;
}
 
ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a%b, y, x);
    y -= a / b * x;
    return d;
}
 
inline ll mod(ll a, ll m) {
    return (a % m + m) % m;
}
 
ll modinv(ll a) {
    ll x, y;
    extGCD(a, MOD, x, y);
    return mod(x, MOD);
}
 
ll COM(ll m,ll n)
{
  if(m<n) return 0;
  if(n<0) return 0;
  if(n==0) return 1;
  if(m==n) return 1;
  return KAI(m)%MOD*modinv(KAI(n)%MOD*KAI(m-n)%MOD)%MOD;
}

ll DEC(ll x,ll m,ll n)
{
  return x%POW(m,n+1)/POW(m,n);
}

ll keta(ll x,ll n)
{
  if(x==0)return 0;
  return keta(x/n,n)+1;
}

ll DIV(ll x,ll n)
{
  if(x==0)return 0;
  return x/n+DIV(x/n,n);
}


int main()
{
  ll x,y,z,ans;
  cin >> x >> y >> z;
  ans=x/(y+z);
  if((y+z)*ans+z>x)ans--;
  printf("%lld",ans);
}