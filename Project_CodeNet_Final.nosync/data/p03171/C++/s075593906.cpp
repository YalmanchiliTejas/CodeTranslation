#include <bits/stdc++.h>
      
#define FOR(i,a,b) for(ll i = (a); i < (ll)(b); i++)
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define PW(x) (1LL<<(x))
#define SZ(x) ((ll)(x).size())

#define pb emplace_back
#define fi first
#define se second

using namespace std;

using ld = long double;
using ll = long long int;

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ll MOD = 1e9+7;
     
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> void UNIQUE(vector<T> &a){ a.erase(unique(a.begin(), a.end()), a.end()); }

template<class S, class T> ostream& operator << (ostream& os, const pair<S, T> v){
  os << "(" << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator << (ostream& os, const vector<T> v){
  for(int i = 0; i < v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator << (ostream& os, const vector<vector<T>> v){
  for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}

ll in(){long long int x; assert(scanf("%lld", &x) == 1); return x;}
ld fin(){double x; assert(scanf("%lf", &x) == 1); return x;}
char yuyushiki[1000010]; string stin(){assert(scanf("%s", yuyushiki) == 1); return yuyushiki;}

// head

struct Mod{
  unsigned n;
  Mod() : n(0){}
  Mod( ll x ){
    if( x < 0 ) n = x%MOD+MOD;
    else n = x%MOD;
  }
};
Mod operator + ( Mod a  , Mod b ){ return Mod( a.n + b.n ); }
Mod operator +=( Mod &a , Mod b ){ return a = a + b; }
Mod operator - ( Mod a ){ return Mod( MOD - a.n ); }
Mod operator - ( Mod a  , Mod b ){ return Mod( a.n + MOD - b.n ); }
Mod operator -=( Mod &a , Mod b ){ return a = a - b; }
Mod operator * ( Mod a  , Mod b ){ return Mod( (ll)a.n * b.n ); }
Mod operator *=( Mod &a , Mod b ){ return a = a * b; }
Mod modpow( Mod x , ll k ){
  Mod res = 1;
  while( k ){
    if( k & 1 ) res *= x;
    k /= 2;
    x *= x;
  }
  return res;
}
ll extgcd( ll a , ll b , ll &x , ll &y ){
  ll d = a;
  if( b != 0 ){
    d = extgcd( b , a % b , y , x );
    y -= a / b * x;
  } else {
    x = 1, y = 0;
  }
  return d;
}
Mod inv( Mod a ){ ll x, y; assert( extgcd( a.n , MOD , x , y ) == 1 ); return Mod( x ); }
Mod operator / ( Mod a  , Mod b ){ return Mod( (ll)a.n * inv(b).n ); }
Mod operator /=( Mod &a , Mod b ){ return a = a / b; }

int main(){

  int n = in();
  vector<ll> a(n);
  REP(i, n){
    a[i] = in();
  }
  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
  REP(i, n + 1){
    dp[i][i] = 0;
    FOR(j, i + 1, n + 1){
      if((j - i) % 2 == n % 2){
        dp[i][j] = -INFLL;
      } else {
        dp[i][j] = INFLL;
      }
    }
  }
  
  FOR(l, 1, n + 1){
    REP(i, n){
      ll j = i + l;
      if(j > n){
        continue;
      }
      if(l % 2 == n % 2){
        ll x = dp[i+1][j] + a[i];
        ll y = dp[i][j-1] + a[j-1];
        dp[i][j] = max(x, y);
      } else {
        ll x = dp[i+1][j] - a[i];
        ll y = dp[i][j-1] - a[j-1];
        dp[i][j] = min(x, y);
      }
    }
  }

  printf("%lld\n", dp[0][n]);
  
  return 0;
}
