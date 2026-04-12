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

ll n;
ll a[64];

int main(){

  n = in();
  REP(i, n){
    a[i] = in();
  }

  ll ans = 0;
  while(1){
    int p = max_element(a, a+n) - a;
    if(a[p] < n){
      break;
    }
    ll c = a[p] / n;
    REP(i, n){
      if(i != p){
        a[i] += c;
      } else {
        a[i] = a[i] % n;
      }
    }
    ans += c;
  }

  printf("%lld\n", ans);
  
  return 0;
}
