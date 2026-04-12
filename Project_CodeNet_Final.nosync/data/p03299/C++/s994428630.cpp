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

ll in(){long long int x; scanf("%lld", &x); return x;}
ld fin(){double x; scanf("%lf", &x); return x;}
char yuyushiki[1000010]; string stin(){scanf( "%s", yuyushiki ); return yuyushiki;}

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

using T = tuple<Mod, Mod, Mod>;

ll n;
ll a[110];

T dfs(ll l, ll r, ll h){
  ll m = *min_element(a+l, a+r);
  vector<ll> v(0);
  v.pb(l-1);
  FOR(i, l, r){
    if(a[i] == m){
      v.pb(i);
    }
  }
  v.pb(r);
  Mod tatejima = modpow(2, SZ(v) - 2);
  Mod yokojima = modpow(2, m-h);
  Mod both = 2;
  REP(i, SZ(v) - 1){
    if(v[i+1] - v[i] > 1){
      auto w = dfs(v[i]+1, v[i+1], m);
      tatejima *= get<0>(w) - get<2>(w) + get<1>(w) * 2;
      yokojima *= get<1>(w);
      both *= get<1>(w);
    }
  }
  // cout << l << " " << r << " " << h << " " << tatejima.n << " " << yokojima.n << " " << both.n << endl;
  return T(tatejima, yokojima, both);
}

int main(){

  n = in();
  REP(i, n){
    a[i] = in();
  }

  auto res = dfs(0, n, 0);
  Mod ans = get<0>(res) + get<1>(res) - get<2>(res);

  printf("%d\n", (int)ans.n);
  
  return 0;
}