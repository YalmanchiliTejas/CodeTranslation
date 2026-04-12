#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll, ll> PLL;
#define chmax(x, y) do { x = max(x, y); } while(0)
#define chmin(x, y) do { x = min(x, y); } while(0)
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, ) (__VA_ARGS__)  // NOLINT
template<typename T>
using reversed_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T> >;

// {{{ Lazy Segment Tree
const ll TYPE_MIN = 0;
const ll TYPE_MAX = 1;
const ll TYPE_SUM = 2;
struct LazySegmentTree {
  ll n, init;
  ll type;
  std::vector<ll> node;  // 値配列
  std::vector<ll> lazy;  // 遅延配列
  std::vector<bool> isOverride;  // 遅延配列の取り扱い（false:加算、true:更新）

  LazySegmentTree(ll N, ll init, ll type) : init(init), type(type) {
    std::vector<ll> v(N, init);
    n = 1;
    while (n < v.size())
      n *= 2;
    node.resize(2 * n - 1, init);
    lazy.resize(2 * n - 1, 0);
    isOverride.resize(2 * n - 1, false);
    for (ll i = 0; i < v.size(); i++)
      node[i + n - 1] = v[i];
    for (ll i = n - 2; i >= 0; i--) {
      switch (type) {
        case TYPE_MIN:
          node[i] = std::min(node[i * 2 + 1], node[i * 2 + 2]);
          break;
        case TYPE_MAX:
          node[i] = std::max(node[i * 2 + 1], node[i * 2 + 2]);
          break;
        case TYPE_SUM:
          node[i] = node[i * 2 + 1] + node[i * 2 + 2];
          break;
      }
    }
  }

  // k番目のノードを評価する (k=0から順に呼ぶ）
  void eval(ll k, ll l, ll r) {
    // - 自ノードの値配列に値を伝播
    if (isOverride[k]) {
      node[k] = lazy[k];  // 区間更新
    } else {
      node[k] += lazy[k];  // 区間加算
    }

    // - 子ノードに遅延配列を伝播
    if (r - l > 1) {
      if (isOverride[k]) {
        // 区間更新
        switch (type) {
          case TYPE_SUM:
            lazy[2 * k + 1] = lazy[k] / 2;
            lazy[2 * k + 2] = lazy[k] / 2;
            break;
          case TYPE_MIN:
          case TYPE_MAX:
            lazy[2 * k + 1] = lazy[k];
            lazy[2 * k + 2] = lazy[k];
            break;
        }
        isOverride[2 * k + 1] = true;
        isOverride[2 * k + 2] = true;
      } else {
        // 区間加算
        switch (type) {
          case TYPE_SUM:
            lazy[2 * k + 1] += lazy[k] / 2;
            lazy[2 * k + 2] += lazy[k] / 2;
            break;
          case TYPE_MIN:
          case TYPE_MAX:
            lazy[2 * k + 1] += lazy[k];
            lazy[2 * k + 2] += lazy[k];
            break;
        }
        isOverride[2 * k + 1] = false;
        isOverride[2 * k + 2] = false;
      }
    }

    // - 自ノードの遅延配列を空にする (0を足すという状態にしておく）
    lazy[k] = 0;
    isOverride[k] = false;
  }

  void add(ll a, ll b, ll x, ll k = 0, ll l = 0, ll r = -1) {
    if (r < 0)
      r = n;

    // 範囲外
    if (b <= l || r <= a) {
      eval(k, l, r);
      return;
    }

    // 完全に含む
    if (a <= l && r <= b) {
      // 最小値を計算する場合
      switch (type) {
        case TYPE_MIN:
        case TYPE_MAX:
          lazy[k] += x;
          break;
        case TYPE_SUM:
          lazy[k] += (r -l) * x;
          break;
      }
      isOverride[k] = false;
      eval(k, l, r);
      return;
    }

    // 子ノードに加算して、結果を自ノードに反映する
    eval(k, l, r);
    add(a, b, x, 2 * k + 1, l, (l + r) / 2);
    add(a, b, x, 2 * k + 2, (l + r) / 2, r);
    // node[k] = node[2*k+1] + node[2*k+2]; // 区間和なので+
    switch (type) {
        case TYPE_MIN:
          node[k] = std::min(node[k * 2 + 1], node[k * 2 + 2]);
          break;
        case TYPE_MAX:
          node[k] = std::max(node[k * 2 + 1], node[k * 2 + 2]);
          break;
        case TYPE_SUM:
          node[k] = node[k * 2 + 1] + node[k * 2 + 2];
          break;
    }
  }

  void update(ll a, ll b, ll x, ll k = 0, ll l = 0, ll r = -1) {
    if (r < 0)
      r = n;

    // 遅延評価
    eval(k, l, r);

    // 範囲外
    if (b <= l || r <= a)
      return;

    // 完全に含む
    if (a <= l && r <= b) {
      switch (type) {
        case TYPE_MIN:
        case TYPE_MAX:
          lazy[k] = x;
          break;
        case TYPE_SUM:
          lazy[k] = (r - l) * x;
          break;
      }
      isOverride[k] = true;
      eval(k, l, r);
      return;
    }

    // 子ノードに更新して、結果を自ノードに反映する
    update(a, b, x, 2 * k + 1, l, (l + r) / 2);
    update(a, b, x, 2 * k + 2, (l + r) / 2, r);
    switch (type) {
        case TYPE_MIN:
          node[k] = std::min(node[k*2+1], node[k*2+2]);
          break;
        case TYPE_MAX:
          node[k] = std::max(node[k*2+1], node[k*2+2]);
          break;
        case TYPE_SUM:
          node[k] = node[k*2+1] + node[k*2+2];
          break;
    }
  }

  ll query(ll a, ll b, ll k = 0, ll l = 0, ll r = -1) {
    if (r < 0)
      r = n;
    if (b <= l || r <= a)
      return init;

    eval(k, l, r);
    if (a <= l && r <= b)
      return node[k];
    ll vl = query(a, b, 2*k+1, l, (l+r)/2);
    ll vr = query(a, b, 2*k+2, (l+r)/2, r);
    switch (type) {
      case TYPE_MIN: return std::min(vl, vr);
      case TYPE_MAX: return std::max(vl, vr);
      case TYPE_SUM: return vl + vr;
    }
    return -1;
  }

  static void test() {
    {
      LazySegmentTree st(5, 0, TYPE_SUM);
      rep(i, 0, 5)
        st.update(i, i+1, i+1);
      assert(st.query(0, 5) == 15);
      st.add(1, 4, 10);
      assert(st.query(0, 5) == 45);
      st.update(1, 3, 10);
      assert(st.query(0, 5) == 40);
    }
    {
      LazySegmentTree st(5, 0, TYPE_SUM);
      rep(i, 0, 5)
        st.update(i, i+1, i+1);
      assert(st.query(0, 5) == 15);
      st.update(1, 3, 10);
      assert(st.query(0, 5) == 30);
      st.add(1, 4, 10);
      assert(st.query(0, 5) == 60);
    }
    {
      LazySegmentTree st(5, 100000000, TYPE_MIN);
      rep(i, 0, 5)
        st.update(i, i+1, i+1);
      assert(st.query(0, 5) == 1);
      st.add(0, 1, 5);
      assert(st.query(0, 5) == 2);
      st.update(1, 3, 5);
      assert(st.query(0, 5) == 4);
    }
    {
      LazySegmentTree st(5, 100000000, TYPE_MIN);
      rep(i, 0, 5)
        st.update(i, i+1, i+1);
      assert(st.query(0, 5) == 1);
      st.update(0, 2, 5);
      assert(st.query(0, 5) == 3);
      st.add(2, 3, 5);
      assert(st.query(0, 5) == 4);
    }
  }
};
// }}}

// ll x = (ll)(1e16) + 2000;
// ll i = 52;

// tie(x, i) = dec(enc(x, i));
// cout << "x = " << x << endl;
// cout << "i = " << i << endl;
ll enc(ll val, ll i) {
  return (val << 6) + i;
}

PLL dec(ll e) {
  return PLL(e >> 6, e & ((1 << 6)-1));
}

ll N;
LazySegmentTree st(100, -1, TYPE_MAX);

signed main() {
  cin >> N;
  rep(i, N) {
    ll x;
    cin >> x;
    st.update(i, i+1, enc(x, i));
  }

  ll x, i, ans = 0;
  while (tie(x, i) = dec(st.query(0, N)), x >= N) {
    ll d = x - (N - 1);
    ll k = (d + N - 1) / N;
    st.add(0, N, k << 6);
    st.add(i, i+1, - (((N + 1) * k) << 6));
    ans += k;
  }
  cout << ans << endl;
  return 0;
}
