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

vector<ll> G[100010];
ll col[100010];

ll dfs1(ll x, ll p){
  ll c = 0;
  ll len = 0;
  ll od = 0;
  YYS(w, G[x]){
    if(w == p){
      continue;
    }
    len = dfs1(w, x) + 1;
    if(col[w] == 0){
      col[x] = 1;
    }
    c++;
    if(len >= 0 && len % 2 == 1){
      od++;
    }
  }
  if(od >= 2){
    puts("First");
    exit(0);
  }
  if(c <= 1){
    return len;
  }
  return -INFLL;
}

void dfs2(ll x, ll p, ll up){
  ll c = up;
  YYS(w, G[x]){
    if(w == p){
      continue;
    }
    c += 1 - col[w];
  }
  if(c == 0){
    // cout << x << endl;
    puts("First");
    exit(0);
  }
  YYS(w, G[x]){
    if(w == p){
      continue;
    }
    ll nc = c - (1 - col[w]);
    ll nup = 0;
    if(nc == 0){
      nup = 1;
    }
    dfs2(w, x, nup);
  }
}

int main(){

  ll n = in();

  REP(i, n-1){
    ll a = in() - 1;
    ll b = in() - 1;
    G[a].pb(b);
    G[b].pb(a);
  }

  ll r = -1;
  REP(i, n){
    if(SZ(G[i]) >= 3){
      r = i;
    }
  }
  if(r == -1){
    if(n % 2 == 1){
      puts("First");
    } else {
      puts("Second");
    }
    return 0;
  }
  // cout << "r = " << r << endl;
  dfs1(r, -1);
  /*
  REP(i, n){
    cout << col[i] << " ";
  }
  cout << endl;
  */
  dfs2(r, -1, 0);

  puts("Second");
  
  return 0;
}
