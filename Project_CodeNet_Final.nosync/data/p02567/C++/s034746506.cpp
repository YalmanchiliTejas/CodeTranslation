#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
#include <stack>
#include <set>
#include <bitset>
#include <functional>
#include <cassert>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define fast_io ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define MOD (long long int)(1e9+7)
#define INF (int)(1e9)
#define LINF (long long int)(1e18)
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define all(v) v.begin(), v.end()
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

ll mpow(ll a, ll b){
  if(b==0) return 1;
  else if(b%2==0){ll memo = mpow(a,b/2); return memo*memo%MOD;}
  else return mpow(a,b-1) * a % MOD;
}
ll lpow(ll a, ll b){
  if(b==0) return 1;
  else if(b%2==0){ll memo = lpow(a,b/2); return memo*memo;}
  else return lpow(a,b-1) * a;
}
ll gcd(ll a, ll b){
  if(b==0) return a;
  else return gcd(b, a%b);
}
vector<ll> kaijo_memo;
ll kaijo(ll n){
  if(kaijo_memo.size() > n) return kaijo_memo[n];
  if(kaijo_memo.size() == 0) kaijo_memo.push_back(1);
  while(kaijo_memo.size() <= n) kaijo_memo.push_back(kaijo_memo[kaijo_memo.size()-1] * kaijo_memo.size() % MOD);
  return kaijo_memo[n];
}
vector<ll> gyaku_kaijo_memo;
ll gyaku_kaijo(ll n){
  if(gyaku_kaijo_memo.size() > n) return gyaku_kaijo_memo[n];
  if(gyaku_kaijo_memo.size() == 0) gyaku_kaijo_memo.push_back(1);
  while(gyaku_kaijo_memo.size() <= n) gyaku_kaijo_memo.push_back(gyaku_kaijo_memo[gyaku_kaijo_memo.size()-1] * mpow(gyaku_kaijo_memo.size(), MOD-2) % MOD);
  return gyaku_kaijo_memo[n];
}

ll nCr(ll n, ll r){
  if(n == r) return 1;//0個の丸と-1個の棒みたいな時に時に効く？不安.
  if(n < r || r < 0) return 0;
  ll ret = 1;
  if(n <= 1e7){
    ret *= kaijo(n); ret %= MOD;
    ret *= gyaku_kaijo(r); ret %= MOD;
    ret *= gyaku_kaijo(n-r); ret %= MOD;
  }else{
    rep(i,r){
      ret *= n-i; ret %= MOD;
      ret *= mpow(r-i, MOD-2); ret %= MOD;
    }
  }
  return ret;
}

vector<ll> yakusu(ll n){
  vector<ll> ret;
  for(ll p = 1; p*p <= n; p++){
    if(n%p == 0){
      ret.push_back(p);
      if(p*p != n){
        ret.push_back(n/p);
      }
    }
  }
  sort(all(ret));
  return ret;
}

map<ll,ll> soinsu(ll n){
  map<ll,ll> mp;
  for(ll p = 2; p*p <= n; p++){
    if(n%p == 0){
      mp[p]++;
      n /= p;
      p--;
    }
  }
  if(n > 1){
    mp[n]++;
  }
  return mp;
}

ll op(ll a, ll b){
  return max(a,b);
}

ll e(){
  return -1;
}

ll target;

bool f(ll x){
  return x < target;
}

int main(void){
  fast_io
  cout<<fixed<<setprecision(15);

  int n,q;cin>>n>>q;
  vector<ll> A(n);

  rep(i,n){
    cin>>A[i];
  }
  segtree<ll, op, e> seg(A);
  rep(_t,q){
    int mode;cin>>mode;
    if(mode==1){
      ll x,y;cin>>x>>y;x--;
      seg.set(x,y);
    }else if(mode==2){
      ll l,r;cin>>l>>r;l--;r--;
      ll ans = seg.prod(l,r+1);
      cout<<ans<<endl;
    }else{
      ll x;
      cin>>x>>target;x--;
      ll ans = seg.max_right<f>(x) + 1;
      cout<<ans<<endl;
    }
  }
  return 0;
}