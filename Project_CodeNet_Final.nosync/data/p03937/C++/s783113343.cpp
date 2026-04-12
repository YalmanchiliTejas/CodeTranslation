#include<bits/stdc++.h>
#define rep(i,m) for(long long i=0; i<m; i++)
#define per(i,m) for(long long i=m-1; i>=0; i--)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define ROF(i,n,m) for(long long i=m-1; i>=n; i--)
#define SORT(v,n) do{sort(v,v+n);reverse(v,v+n);}while(0)
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
  if(n%2==0)return POW(x*x,n/2)%MOD;
  return x%MOD*POW(x,n-1)%MOD;
}

ll POW2(ll x,ll n){
  if(n==0)return 1;
  if(n%2==0)return POW2(x*x,n/2);
  return x*POW2(x,n-1);
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
 
ll KAI2(ll m)
{
  if(m<0) return 0;
  if(m==0) return 1;
  return m*KAI2(m-1);
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

ll COM2(ll m,ll n)
{
  if(m<n) return 0;
  if(n<0) return 0;
  if(n==0) return 1;
  if(m==n) return 1;
  return KAI2(m)/KAI2(n)/KAI2(m-n);
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

ll ORD(ll x,ll n)
{
  if(x==0)return INF;
  if(x%n!=0)return 0;
  return 1+ORD(x/n,n);
}

int main()
{
  ll h,w,b[10][10]={};
  char a[10][10]={};
  cin >> h >> w;
  b[0][0]=1;
  rep(i,h)rep(j,w)cin >> a[i][j];
  rep(i,h){
    rep(j,w){
      if(a[i+1][j]=='#'&&a[i][j+1]!='#'&&b[i][j]==1)b[i+1][j]=1;
      if(a[i][j+1]=='#'&&a[i+1][j]!='#'&&b[i][j]==1)b[i][j+1]=1;
    }
  }
  rep(i,h){
    rep(j,w){
      if(a[i][j]=='#'&&b[i][j]==0){
        printf("Impossible");
        return 0;
      }
    }
  }
  if(b[h-1][w-1]==1)printf("Possible");
  else printf("Impossible");
}
