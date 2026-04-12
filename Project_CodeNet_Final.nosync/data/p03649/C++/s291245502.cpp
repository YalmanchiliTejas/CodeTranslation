#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) (int)x.size()
#define pb(x) push_back(x)
#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<ll, ll> point;

const int off = 1 << 6;

struct Tournament{
  point t[2 * off];
  ll p[2 * off];
  Tournament() { REP(i, 2 * off) { t[i] = point(0, 0); p[i] = 0; } }
  void prop(int x){
    t[x].first += p[x];
    if(x < off){
      p[x * 2] += p[x];
      p[x * 2 + 1] += p[x];
    }
    p[x] = 0;
  }
  point merge(point A, point B){
    if(A.first < B.first) swap(A, B);
    return A;
  }
  void dodaj(int x, ll val){
    x += off; t[x] = point(val, x - off);
    for( x /= 2; x > 0; x /= 2)
      t[x] = merge(t[x * 2], t[x * 2 + 1]);
  }
  void update(int x, int lo, int hi, int a, int b, ll val){
    prop(x);
    if(lo >= b || hi <= a) return;
    if(lo >= a && hi <= b) { p[x] += val; prop(x); return; }
    int mid = (lo + hi) >> 1;
    update(x * 2, lo, mid, a, b, val); update(x * 2 + 1, mid, hi, a, b, val);
    t[x] = merge(t[x * 2], t[x * 2 + 1]);
  }
  point get(){
    prop(1);
    return t[1];
  }
} T;

int n;
ll sol;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n;
  REP(i, n){
    ll x; cin >> x;
    T.dodaj(i, x);
  }
  //TRACE(T.get().first);
  while(T.get().first >= n){
    point x = T.get();
    ll val = x.first;
    ll pos = x.second;
    ll add = val / n;
    sol += add;

    T.update(1, 0, off, pos, pos + 1, - add * n - add);
    T.update(1, 0, off, 0, n, add);
  }
  cout << sol;
}
