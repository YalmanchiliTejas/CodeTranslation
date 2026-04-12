#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b)-1; i >= (a); --i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pll> vll;

const int N = 212345;
const ll inf = 1e18;
ll st[4*N], lazy[4*N];
int n, m;

void push(int tl, int tr, int id) {
  lazy[id*2] += lazy[id];
  lazy[id*2+1] += lazy[id];
  st[id*2] += lazy[id];
  st[id*2+1] += lazy[id];
  lazy[id] = 0;
}

ll qmax(int l, int r, int tl=0, int tr=n-1, int id=1) {
  if (tr < l or tl > r) return -inf;
  if (l <= tl and r >= tr) return st[id];
  push(tl, tr, id);
  int tm = (tl+tr)/2;
  return max(qmax(l, r, tl, tm, id*2), qmax(l, r, tm+1, tr, id*2+1));
}

void upd(int l, int r, ll x, int tl=0, int tr=n-1, int id=1) {
  if (l > tr or r < tl) return;
  if (l <= tl and r >= tr) {
    st[id] += x;
    lazy[id] += x;
    return;
  } 
  push(tl, tr, id);
  int tm = (tl+tr)/2;
  upd(l, r, x, tl, tm, id*2); upd(l, r, x, tm+1, tr, id*2+1);
  st[id] = max(st[id*2], st[id*2+1]);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  rep(i,0,4*N) {
    st[i] = 0;
    lazy[i] = 0;
  }

  cin >> n >> m;

  vl cst(n+1);
  vector<vll> out(n+1);
  rep(i,0,m) {
    int l, r, a;
    cin >> l >> r >> a;
    --l; --r;
    out[r+1].eb(l, a);
    cst[l] += a;
    cst[r+1] -= a;
  }

  rep(i,1,n+1) cst[i] += cst[i-1];

  ll ans = 0;

  rep(i,0,n) {
    for (auto p: out[i]) {
      ll l, a;
      tie(l, a) = p;
      upd(l, i-1, a);
    }
    if (i and qmax(0,i-1)>0) upd(i, i, qmax(0, i-1));
    ckmax(ans, qmax(i, i)+cst[i]);
  }

  cout << ans << '\n';
}