#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ull = unsigned long long;
//#define int ll
using vb = vector<bool>; using vvb = vector<vb>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
template<class T> using V = vector<T>;
template<class T> using VV = vector<V<T>>;
#define fi first
#define se second
#define maxs(x,y) (x=max(x,y))
#define mins(x,y) (x=min(x,y))
using pii = pair<int,int>; using pll = pair<ll,ll>;
#define FOR(i,a,b) for(ll i = (a); i < (ll)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(ll i = (ll)(b)-1;i >= a;--i)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define eb(val) emplace_back(val)
const double PI = acos(-1), EPS = 1e-10;
const ll MOD = 1e9+7;
ll power(ll a,ll n,ll modu = 1e9+7){
  ll res = 1,r = a;
  for (; n > 0;n>>=1,r*=r,r%=modu) res *= (n & 1? r:1),res%=modu;
  return res;
}
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,m,k;
  cin >> n >> m >> k;
  ll facl = 1;
  FOR(i,1,n*m-2+1){
    facl *= i;
    facl %= MOD;
  }
  ll facr = 1;
  FOR(i,1,k-2+1){
    facr *= i;
    facr %= MOD;
  }
  FOR(i,1,n*m-k+1){
    facr *= i;
    facr %= MOD;
  }
  facr = power(facr,MOD-2);
  facl *= facr;
  facl %= MOD;
  ll sum = 0;
  REP(i,n){
    sum += (n-i)*m%MOD*m*i;
    sum %= MOD;
  }
  //cout << sum <<endl;
  FOR(i,1,m){
    sum += (m-i)*n%MOD*n*i;
    sum %= MOD;
  }
  //cout << sum << endl;
  cout << sum * facl%MOD << endl;
}

