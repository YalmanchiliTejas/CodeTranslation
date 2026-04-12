#include <bits/stdc++.h>
      
#define FOR(i,a,b) for( ll i = (a); i < (ll)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
#define SZ(x) ((ll)(x).size())
#define SHOW(x) cout << #x << " = " << x << endl
#define SHOWA(x,n) for( int yui = 0; yui < n; yui++ ){ cout << x[yui] << " "; } cout << endl

#define pb emplace_back
#define fi first
#define se second

using namespace std;

typedef long double ld;
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vl> ml;
typedef vector<vd> md;
typedef vector<vi> mi;
     
const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-12;
const ll MOD = 1e9+7;
     
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }

ll in(){ long long int x; scanf( "%lld" , &x ); return x; }
char yuyushiki[1000010]; string stin(){ scanf( "%s" , yuyushiki ); return yuyushiki; }

// head

ll n;
ll a[200010][2];

using T = tuple<ll, ll, ll>;

ll mv(set<T> &ss){
  return get<0>(*ss.begin());
}

ll Mv(set<T> &ss){
  auto ite = ss.end();
  ite--;
  return get<0>(*ite);
}

int main(){

  n = in();
  REP( i , n ){
    ll s = in();
    ll t = in();
    a[i][0] = min(s, t);
    a[i][1] = max(s, t);
  }

  ll mx = INFLL, Mx = -INFLL;
  ll my = INFLL, My = -INFLL;
  REP( i , n ){
    chmin(mx, a[i][0]);
    chmax(Mx, a[i][0]);
    chmin(my, a[i][1]);
    chmax(My, a[i][1]);
  }

  ll ans = (Mx - mx) * (My - my);

  ll lr = My - mx;

  vector<T> v;
  REP( i , n ){
    REP( j , 2 ){
      v.pb(a[i][j], i, j);
    }
  }
  SORT(v);

  if(get<1>(v[0]) == get<1>(v[2*n-1])){
    cout << ans << endl;
    return 0;
  }

  set<T> ss;
  REP( i , 2*n-1 ){
    ll s, t, u;
    tie(s, t, u) = v[i];
    if(u == 0){
      ss.insert(v[i]);
    }
  }

  REP( i , 2*n-1 ){
    ll s, t, u;
    tie(s, t, u) = v[i];
    if(u == 1){
      break;
    }
    ss.erase(ss.find(v[i]));
    ss.insert(T(a[t][1], t, 1LL));
    chmin(ans, lr * (Mv(ss) - mv(ss)));
  }

  cout << ans << endl;

  return 0;
}
