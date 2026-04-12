//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

template <class S, class F>
struct SegTreeL {
  using FX = function<S(S, S)>;
  using FA = function<S(S, F)>;
  using FF = function<F(F, F)>;
  int n, _n, log;
  FX fx;
  FA fa;
  FF ff;
  const S es;
  const F ef;
  vector<S> dat;
  vector<F> laz;
  SegTreeL(int n_, FX fx_, FA fa_, FF ff_, S es_, F ef_)
    : fx(fx_), fa(fa_), ff(ff_), es(es_), ef(ef_), _n(n_), log(__builtin_ctz(n_)) {
      n = 1;
      while(n_ > n) n <<= 1;
      dat.assign(n*2-1, es);
      laz.assign(n*2-1, ef);
  }
  SegTreeL(vector<S> &v, FX fx_, FA fa_, FF ff_, S es_, F ef_)
    : fx(fx_), fa(fa_), ff(ff_), es(es_), ef(ef_), n(1), _n(int(v.size())), log(__builtin_ctz(_n)) {
      while(_n > n) n <<= 1;
      dat.assign(n*2-1, es);
      laz.assign(n*2-1, ef);
      copy(v.begin(), v.end(), dat.begin()+n-1);
      build();
  }
  inline int chld(int k) {return k*2+1;}
  inline int chrd(int k) {return k*2+2;}
  void set(int i, S s) {dat[i+n-1] = s;}
  void build() {
    for(int k = n-2; k >= 0; k--) dat[k] = fx(dat[chld(k)], dat[chrd(k)]);
  }
  void eval(int k) {
    if(laz[k] == ef) return;
    if(k < n-1) {
      laz[chld(k)] = ff(laz[chld(k)], laz[k]);
      laz[chrd(k)] = ff(laz[chrd(k)], laz[k]);
    }
    dat[k] = fa(dat[k], laz[k]);
    laz[k] = ef;
  }
  void update(int a, int b, F x, int k, int l, int r) {
    eval(k);
    if(a <= l and r <= b) {
      laz[k] = ff(laz[k], x);
      eval(k);
    }
    else if(a < r and l < b) {
      update(a, b, x, chld(k), l, (l+r)>>1);
      update(a, b, x, chrd(k), (l+r)>>1, r);
      dat[k] = fx(dat[chld(k)], dat[chrd(k)]);
    }
  }
  void update(int a, int b, F x) {update(a, b, x, 0, 0, n);}
  S query(int a, int b, int k, int l, int r) {
    eval(k);
    if(r <= a or b <= l) return es;
    else if(a <= l and r <= b) return dat[k];
    else {
      S vl = query(a, b, chld(k), l, (l+r)>>1);
      S vr = query(a, b, chrd(k), (l+r)>>1, r);
      return fx(vl, vr);
    }
  }
  S query(int a, int b) {return query(a, b, 0, 0, n);}
  template<class G>
  int max_right(int l, G g) {
    assert(g(es));
    if(l == _n) return _n;
    l += n;
    for(int i = log; i >= 0; i--) eval((l>>i)-1);
    S now = es;
    do{
      while(~l&1) l >>= 1;
      if(!g(fx(now, dat[l-1]))) {
        while(l < n) {
          eval(l-1);
          l <<= 1;
          if(g(fx(now, dat[l-1]))) {
            now = fx(now, dat[l++ - 1]);
          }
        }
        return l-n;
      }
      now = fx(now, dat[l++ - 1]);
    } while((l & -l) != l);
    return _n;
  }
  template<class G>
  int min_left(int r, G g) {
    assert(g(es));
    if(r == 0) return 0;
    r += n;
    for(int i = log; i >= 0; i--) eval(((r-1)>>i)-1);
    S now = es;
    do{
      r--;
      while(r > 1 and (r&1)) r >>= 1;
      if(!g(fx(dat[r-1], now))) {
        while(r < n) {
          eval(r-1);
          r = chld(r);
          if(g(fx(dat[r-1], now))) {
            now = fx(dat[--r], now);
          }
        }
        return r+1-n;
      }
      now = fx(dat[r-1], now);
    } while((r & -r) != r);
    return 0;
  }
  //debug
  inline const S operator[](const int i) {return query(i, i+1);}
  void print() {for(int i = 0; i < n; i++) cout << (*this)[i] << (i == n-1?'\n':' ');}
};



int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  vector<int> a(n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  auto fx = [](int i, int j)->int {return max(i, j);};
  SegTreeL<int, int> seg(a, fx, [](int i, int j)->int{return j;}, fx, INT_MIN, INT_MIN);
  while(q--) {
    int type, x, y;
    scanf("%d%d%d", &type, &x, &y);
    if(type == 1) {
      seg.update(x-1, x, y);
    }
    if(type == 2) {
      printf("%d\n", seg.query(x-1, y));
    }
    if(type == 3) {
      printf("%d\n", seg.max_right(x-1, [y](int X)->bool{return X < y;})+1);
    }
  }
}