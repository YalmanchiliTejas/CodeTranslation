#include<bits/stdc++.h>
#include<bitset>


using namespace std;

#define M 1000000007
#define pb push_back
#define f first
#define s second
#define rep(i, st, ed) for(ll i=st; i<ed; i++)
#define repn(i, st, ed) for(ll i=st; i<=ed; i++)
#define repb(i, ed, st) for(ll i=ed; i>=st; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef unsigned long long int llt;
typedef long double ld;

const long double PI  =3.141592653589793238463;
const int N = 2e5 + 10;
const ll INF = 1LL << 60;

template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}



// Main Code

ll ppow(ll x, ll y, ll mod)
{
  ll res = 1;
  while(y > 0){
    if(y&1)
      res = (res * x)%mod;
    y = y >> 1;
    x = (x * x)%mod;
  }
  return res;
}

// Factorial with dp
ll factdp[N];
ll fact(ll x)
{
  if(x == 0) return 1;
  if(x == 1) return 1;
  if(factdp[x] != 0) return factdp[x];
  return factdp[x] = (x*fact(x-1))%M;
}
// Combination
ll modcomb(ll n, ll r)
{
  if(n < r) return 0;
  ll res = fact(n);
  (res *= ppow(fact(r), M-2, M)) %= M;
  (res *= ppow(fact(n-r), M-2, M)) %= M;
  return res;
}

int main()
{
	ll n, m, k;
	cin>>n>>m>>k;
	ll ansn = 0;
	ll ansb = 0;
	ll ans = 1;
	rep(i, 1, n)
	{
		ansn = (ansn + (n - i)*i) % M;
	}
	ansn = (ansn * (m * m) % M) % M;
	rep(i, 1, m)
	{
		ansb = (ansb + (m - i)*i) % M;
	}
	ansb = (ansb * (n * n) % M) % M;
	ans = (ansb + ansn) % M;
	ans = (ans * modcomb(n*m-2, k-2)) % M;
	cout<<ans<<endl;
} 
