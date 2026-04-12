#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb(x) push_back(x)

typedef long long ll;
typedef pair<ll, ll> point;

const int off = 1 << 18, MAXN = 2e5 + 5;
const ll inf = 1e17;

ll n, m;
vector <point> r[MAXN];

struct Tournament{
  ll t[2 * off], p[2 * off];
  Tournament(){
    REP(i, 2 * off){
      t[i] = 0;
      p[i] = 0;
    }
  }
  void prop(int x){
    if(p[x] == 0) return;
    t[x] += p[x];
    if(x < off){
      p[x * 2] += p[x];
      p[x * 2 + 1] += p[x];
    }
    p[x] = 0;
  }
  void postavi(ll x, int pos){
    pos += off; t[pos] = x; pos >>= 1;
    for( ; pos > 0; pos >>= 1)
      t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
  }
  void update(int x, int lo, int hi, int a, int b, ll add){
    prop(x);
    if(lo >= b || hi <= a) return;
    if(lo >= a && hi <= b) { p[x] += add; prop(x); return; }
    int mid = (lo + hi) >> 1;
    update(x * 2, lo, mid, a, b, add); update(x * 2 + 1, mid, hi, a, b, add);
    t[x] = max(t[x * 2], t[x * 2 + 1]);
  }
  ll get(int x, int lo, int hi, int a, int b){
    prop(x);
    if(lo >= b || hi <= a) return 0;
    if(lo >= a && hi <= b) return t[x];
    int mid = (lo + hi) >> 1;
    return max( get(x * 2, lo, mid, a, b), get(x * 2 + 1, mid, hi, a, b) );
  }
} T;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n >> m;
  REP(i, m){
    ll a, b, c; cin >> a >> b >> c; a --; b --;
    r[b].pb(point(a, c));
  }
  REP(i, n){
    ll x = T.get(1, 0, off, 0, off);
    T.postavi(x, i);

    for(auto it : r[i])
      T.update(1, 0, off, it.first, i + 1, it.second);
  }
  cout << T.get(1, 0, off, 0, off);
}
