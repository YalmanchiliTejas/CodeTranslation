#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

template <class Monoid, class OpMonoid>
class LazySegmentTree {
  using FuncMM = std::function<Monoid(Monoid, Monoid)>;
  using FuncMO = std::function<Monoid(Monoid, OpMonoid, int)>;
  using FuncOO = std::function<OpMonoid(OpMonoid, OpMonoid)>;

  const FuncMM funcMM;
  const FuncMO funcMO;
  const FuncOO funcOO;
  const Monoid monoidIdentity;
  const OpMonoid opMonoidIdentity;

  int N;
  std::vector<Monoid> dat;
  std::vector<OpMonoid> lazy;

  void setLazy(int k, const OpMonoid& om) { lazy[k] = funcOO(lazy[k], om); }
  void push(int k, int len) {
    if (lazy[k] == opMonoidIdentity) return;
    if (k < N) {
      setLazy(2 * k + 0, lazy[k]);
      setLazy(2 * k + 1, lazy[k]);
    }
    dat[k] = funcMO(dat[k], lazy[k], len);
    lazy[k] = opMonoidIdentity;
  }

 public:
  LazySegmentTree(int n, const FuncMM funcMM, const FuncMO funcMO,
                  const FuncOO funcOO, const Monoid monoidIdentity,
                  const OpMonoid opMonoidIdentity)
      : funcMM(funcMM),
        funcMO(funcMO),
        funcOO(funcOO),
        monoidIdentity(monoidIdentity),
        opMonoidIdentity(opMonoidIdentity) {
    N = 1;
    while (N < n) N *= 2;
    dat.resize(2 * N, monoidIdentity);
    lazy.resize(2 * N, opMonoidIdentity);
  }

  void set(int i, const Monoid& v) { dat[N + i] = v; }

  void init() {
    for (int i = N - 1; i > 0; i--) {
      dat[i] = funcMM(dat[2 * i + 0], dat[2 * i + 1]);
    }
  }

  void update(int s, int t, const OpMonoid& om) { update(s, t, om, 1, 0, N); }
  void update(int s, int t, const OpMonoid& om, int k, int l, int r) {
    push(k, r - l);
    if (r <= s || t <= l) return;
    if (s <= l && r <= t) {
      setLazy(k, om);
      push(k, r - l);
      return;
    }
    update(s, t, om, 2 * k + 0, l, (l + r) / 2);
    update(s, t, om, 2 * k + 1, (l + r) / 2, r);
    dat[k] = funcMM(dat[2 * k + 0], dat[2 * k + 1]);
  }

  Monoid query(int s, int t) { return query(s, t, 1, 0, N); }
  Monoid query(int s, int t, int k, int l, int r) {
    push(k, r - l);
    if (r <= s || t <= l) return monoidIdentity;
    if (s <= l && r <= t) return dat[k];
    Monoid vl = query(s, t, 2 * k + 0, l, (l + r) / 2);
    Monoid vr = query(s, t, 2 * k + 1, (l + r) / 2, r);
    return funcMM(vl, vr);
  }
};

vector<pair<int,int>> v[200005];
struct VAL {
  ll x;
};
struct OP {
  ll a;
};
bool operator==(const OP& a, const OP& b){
  return a.a == b.a;
}

int main(){
  int N, M;
  cin >> N >> M;
  rep(i,M){
    int l, r, a;
    cin >> l >> r >> a;
    v[r].emplace_back(l,a);
  }

  auto funcMM = [](const VAL& a, const VAL& b) {
    VAL ret;
    ret.x = max(a.x, b.x);
    return ret;
  };
  auto funcMO = [](const VAL& a, const OP& b, int k) {
    VAL ret;
    ret.x = a.x + b.a;
    return ret;
  };
  auto funcOO = [](const OP& a, const OP& b) {
    OP ret;
    ret.a = a.a + b.a;
    return ret;
  };

  LazySegmentTree<VAL, OP> dp(N+5, funcMM, funcMO, funcOO, (VAL){0}, (OP){0});
  dp.init();
  REP(i,1,N+1){
    ll tmp = dp.query(1,i).x;
    dp.update(i,i+1,(OP){tmp});
    rep(j,v[i].size()){
      dp.update(v[i][j].first, i+1, (OP){(ll)(v[i][j].second)});
    }
  }

  //rep(i,N+1){
  //  cout << dp.query(i,i+1).x << endl;
  //}
  cout << dp.query(0,N+1).x << endl;
  
  return 0;
}
