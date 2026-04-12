#include <bits/stdc++.h>
typedef long long int ll;
#define rep(i, a) for (ll i = 0; i < (a); i++)
 
using namespace std;

struct LazySegmentTree {
  ll n, init;
  std::function<ll(ll, ll)> f;
  vector<ll> node; // 値配列
  vector<ll> lazy; // 遅延配列
  vector<bool> isOverride; // 遅延配列の取り扱い（false:加算、true:更新）

  LazySegmentTree(ll N, ll init, function<ll(ll,ll)> f) : init(init), f(f) {
    vector<ll> v(N, init);
    n = 1;
    while (n < v.size())
      n *= 2;
    node.resize(2*n-1, init);
    lazy.resize(2*n-1, 0);
    isOverride.resize(2*n-1, false);
    for (ll i=0; i<v.size(); i++)
      node[i+n-1] = v[i];
    for (ll i=n-2; i>=0; i--) {
      node[i] = f(node[i*2+1], node[i*2+2]);
    }
  }

  // k番目のノードを評価する (k=0から順に呼ぶ）
  void eval(ll k, ll l, ll r) {
    //if(lazy[k] == 0) {
    //  return;
    //}
    // - 自ノードの値配列に値を伝播
    if (isOverride[k]) {
      node[k] = lazy[k]; // 区間更新
    } else {
      node[k] += lazy[k]; // 区間加算
    }

    // - 子ノードに遅延配列を伝播
    if (r - l > 1) {
      if (isOverride[k]) {
        node[2*k+1] = lazy[k]; // 区間更新
        node[2*k+2] = lazy[k];
        isOverride[2*k+1] = true;
        isOverride[2*k+2] = true;
      } else {
        // 総計を計算する場合
        //  lazy[2*k+1] += lazy[k] / 2; // 区間加算
        //  lazy[2*k+2] += lazy[k] / 2;
        // 最小値を計算する場合
        lazy[2*k+1] += lazy[k]; // 区間加算
        lazy[2*k+2] += lazy[k];
        isOverride[2*k+1] = false;
        isOverride[2*k+2] = false;
      }
    }

    // - 自ノードの遅延配列を空にする (0を足すという状態にしておく）
    lazy[k] = 0;
    isOverride[k] = false;
  }

  void add(ll a, ll b, ll x, ll k=0, ll l=0, ll r=-1) {
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
      lazy[k] += x;
      // 総和を計算する場合
      // lazy[k] += (r-l) * x;
      isOverride[k] = false;
      eval(k, l, r);
      return;
    }

    // 子ノードに加算して、結果を自ノードに反映する
    eval(k, l, r);
    add(a, b, x, 2*k+1, l, (l+r)/2);
    add(a, b, x, 2*k+2, (l+r)/2, r);
    // node[k] = node[2*k+1] + node[2*k+2]; // 区間和なので+
    node[k] = f(node[2*k+1], node[2*k+2]);
  }

  void update(ll a, ll b, ll x, ll k=0, ll l=0, ll r=-1) {
    if (r < 0)
      r = n;

    // 遅延評価
    eval(k, l, r);

    // 範囲外
    if (b <= l || r <= a)
      return;

    // 完全に含む
    if (a <= l && r <= b) {
      lazy[k] = x;
      isOverride[k] = true;
      eval(k, l, r);
      return;
    }

    // 子ノードに更新して、結果を自ノードに反映する
    update(a, b, x, 2*k+1, l, (l+r)/2);
    update(a, b, x, 2*k+2, (l+r)/2, r);
    //node[k] = node[2*k+1] + node[2*k+2]; // 区間和なので+
    node[k] = f(node[2*k+1], node[2*k+2]);
  }

  ll query(ll a, ll b, ll k=0, ll l=0, ll r=-1) {
    if (r < 0)
      r = n;
    if (b <= l || r <= a)
      return init;

    eval(k, l, r);
    if (a <= l && r <= b)
      return node[k];
    ll vl = query(a, b, 2*k+1, l, (l+r)/2);
    ll vr = query(a, b, 2*k+2, (l+r)/2, r);
    // return vl + vr; // 区間和なので+
    return f(vl, vr);
  }
  static void test() {
    {
      LazySegmentTree st(5, 0, [](ll x, ll y){ return x+y;});
      rep(i, 5)
        st.update(i, i+1, i+1);
      assert(st.query(0, 5) == 15);
      st.add(1,4,10);
      assert(st.query(0, 5) == 45);
      st.update(1,3,10);
      assert(st.query(0, 5) == 40);
    }
    {
      LazySegmentTree st(5, 0, [](ll x, ll y){ return x+y;});
      rep(i, 5)
        st.update(i, i+1, i+1);
      assert(st.query(0, 5) == 15);
      st.update(1,3,10);
      assert(st.query(0, 5) == 30);
      st.add(1,4,10);
      assert(st.query(0, 5) == 60);
    }
    {
      LazySegmentTree st(5, 100000000, [](ll x, ll y){ return min(x,y);});
      rep(i, 5)
        st.update(i, i+1, i+1);
      assert(st.query(0, 5) == 1);
      st.add(0,1,5);
      assert(st.query(0, 5) == 2);
      st.update(1,3,5);
      assert(st.query(0, 5) == 4);
    }
    {
      LazySegmentTree st(5, 100000000, [](ll x, ll y){ return min(x,y);});
      rep(i, 5)
        st.update(i, i+1, i+1);
      assert(st.query(0, 5) == 1);
      st.update(0,2,5);
      assert(st.query(0, 5) == 3);
      st.add(2,3,5);
      assert(st.query(0, 5) == 4);
    }
  }
};


ll N, M;
LazySegmentTree st(3000000, 0, [](ll x, ll y) { return max(x, y); });
vector<pair<ll, ll>> blocks[3000000];

signed main() {
  //LazySegmentTree::test();
  cin >> N >> M;
  rep(i, M){
    ll l, r, a;
    cin >> l >> r >> a;
    blocks[r].push_back({l, a});
  }
  for (ll i=1; i<=N; i++) {
    ll m = st.query(0, i);
    st.update(i, i+1, m);
    for (auto b : blocks[i]) {
      st.add(b.first, i+1, b.second);
    }
  }
  //for (int i=0; i<=N+1; i++) {
  //  printf("seg[%d] = %d\n", i, st.query(i, i+1));
  //}
  //rep(i, st.node.size()) {
  //  printf("node[%d] = %d\n", i, st.node[i]);
  //}

  cout << st.query(0, N+1) << endl;
  return 0;
}
