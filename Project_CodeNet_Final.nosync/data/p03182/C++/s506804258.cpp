#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

//0-indexedで用いる (実装は1-indexedの配列だけど
//set(k,x) k番目の要素にxを代入する
//build() (代入で作った場合)セグメント木を構築するのに必要
//query(a,b) 区間[a,b)に対して二項演算した結果を返す
//update(k,x) k(0-indexed)番目の要素をxに変更する
//operator[k] k(0-indexed)番目の要素を返す


template< typename Monoid, typename OperatorMonoid = Monoid >
struct LazySegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;
  using G = function< Monoid(Monoid, OperatorMonoid, int) >;
  using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;

  int sz;
  vector< Monoid > data;
  vector< OperatorMonoid > lazy;
  const F f;
  const G g;
  const H h;
  const Monoid M1;
  const OperatorMonoid OM0;


  LazySegmentTree(int n, const F f, const G g, const H h,
                  const Monoid &M1, const OperatorMonoid OM0)
     : f(f), g(g), h(h), M1(M1), OM0(OM0) {
    sz = 1;
    while(sz < n) sz <<= 1;
    data.assign(2 * sz, M1);
    lazy.assign(2 * sz, OM0);
  }

  void set(int k, const Monoid &x) {
    data[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      data[k] = f(data[2 * k + 0], data[2 * k + 1]);
    }
  }

  void propagate(int k, int len) {
    if(lazy[k] != OM0) {
      if(k < sz) {
        lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
        lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
      }
      data[k] = g(data[k], lazy[k], len);
      lazy[k] = OM0;
    }
  }

  Monoid update(int a, int b, const OperatorMonoid &x, int k, int l, int r) {
    propagate(k, r - l);
    if(r <= a || b <= l) {
      return data[k];
    } else if(a <= l && r <= b) {
      lazy[k] = h(lazy[k], x);
      propagate(k, r - l);
      return data[k];
    } else {
      return data[k] = f(update(a, b, x, 2 * k + 0, l, (l + r) >> 1),
                         update(a, b, x, 2 * k + 1, (l + r) >> 1, r));
    }
  }

  Monoid update(int a, int b, const OperatorMonoid &x) {
    return update(a, b, x, 1, 0, sz);
  }


  Monoid query(int a, int b, int k, int l, int r) {
    propagate(k, r - l);
    if(r <= a || b <= l) {
      return M1;
    } else if(a <= l && r <= b) {
      return data[k];
    } else {
      return f(query(a, b, 2 * k + 0, l, (l + r) >> 1),
               query(a, b, 2 * k + 1, (l + r) >> 1, r));
    }
  }

  Monoid query(int a, int b) {
    return query(a, b, 1, 0, sz);
  }

  Monoid operator[](const int &k) {
    return query(k, k + 1);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<pair<ll, ll> > range[N];
  rep(i,M){
    int l,r,a;
    cin >> l >> r >> a;
    l--;r--;
    range[r].pb(mp(l,a));
  }
  
  
  //  SegmentTree(n,f,g,h,M1,OM0):= サイズ n の初期化。ここで f は2つの区間の要素をマージする二項演算, g は要素と作用素をマージする二項演算(第三引数は対応する区間の長さ), h は作用素同士をマージする二項演算, M1 はモノイドの単位元, OM0 は作用素の単位元である。
  //f 二つの区間の連結方法
  //g 遅延させた作用を区間に作用させるときの方法
  //h 作用同士を結合させる方法
  //区間はM1,作用素はOM0で初期化される。区間がM1、作用素がOM0の時とき更新は行われない  
  //区間加算 区間最小値
  // PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H&lang=ja
  LazySegmentTree< ll > seg(N, [](ll a, ll b) { return max(a,b); }, [](ll a, ll b, ll len) { return a+b; }, [](ll a, ll b) { return a+b; }, 0, 0);
  rep(i,N) seg.set(i,0);  
  seg.build();
  rep(i,N){
    ll tmp=seg.query(0,i);
    int tn=range[i].size();
    ll tsum=0;
    rep(j,tn) tsum+=range[i][j].second;
    seg.update(i,i+1,tsum+tmp);
    rep(j,tn){
      int l,a;tie(l,a)=range[i][j];
      seg.update(l,i,a);      
    }
  }
    cout << max(seg.query(0,N+1),0LL) << endl;
  return 0;
}
