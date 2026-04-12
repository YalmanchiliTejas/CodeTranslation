//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

template<class T>
struct SegTree {
  using FX = function<T(T, T)>;
  int n, _n;
  FX fx;
  const T ex;
  vector<T> dat;
  SegTree(int n_, FX fx_, T ex_):fx(fx_), ex(ex_), n(1), _n(n_) {
    while(n < n_) n <<= 1;
    dat.assign((n<<1)-1, ex);
  }
  SegTree(vector<T> &v, FX fx_, T ex_):fx(fx_), ex(ex_), n(1), _n(int(v.size())) {
    int n_ = int(v.size());
    while(n < n_) n <<= 1;
    dat.assign((n<<1)-1, ex);
    copy(v.begin(), v.end(), dat.begin()+n-1);
    for(int i = n-2; i >= 0; i--) dat[i] = fx(dat[chld(i)], dat[chrd(i)]);
  }
  inline int chld(int k) {return (k<<1)+1;}
  inline int chrd(int k) {return (k<<1)+2;}
  void update(int i, T x) {
    i += n-1;
    dat[i] = x;
    while(i) {
      i = (i-1)>>1;
      dat[i] = fx(dat[chld(i)], dat[chrd(i)]);
    }
  }
  inline T query(int a, int b) {return query(a, b, 0, 0, n);}
  T query(int a, int b, int k, int l, int r) {
    if(r <= a || b <= l) return ex;
    if(a <= l && r <= b) return dat[k];
    T vl = query(a, b, chld(k), l, (l+r)>>1);
    T vr = query(a, b, chrd(k), (l+r)>>1, r);
    return fx(vl, vr);
  }
  template<class F>
  int max_right(int l, F f) {
    assert(f(ex));
    if(l == _n) return _n;
    l += n;
    T now = ex;
    do {
      while(~l&1) l >>= 1;
      if(!f(fx(now, dat[l-1]))) {
        while(l < n) {
          l <<= 1;
          if(f(fx(now, dat[l-1]))) {
            now = fx(now, dat[l++ - 1]);
          }
        }
        return l-n;
      }
      now = fx(now, dat[l++ - 1]);
    } while((l & -l) != l);
    return _n;
  }
  template<class F>
  int min_left(int r, F f) {
    assert(f(ex));
    if(r == 0) return 0;
    r += n;
    T now = ex;
    do {
      r--;
      while(r > 1 and r&1) r >>= 1;
      if(!f(fx(dat[r-1], now))) {
        while(r < n) {
          r = chld(r);
          if(f(fx(dat[r-1], now))) {
            now = fx(dat[--r], now);
          }
        }
        return r+1-n;
      }
      now = fx(dat[r-1], now);
    } while((r & -r) != r);
    return 0;
  }
  const T &operator[](int idx) const {return dat[idx+n-1];}
};



int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  vector<int> a(n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  reverse(a.begin(), a.end());
  SegTree<int> seg(a, [](int i, int j)->int {return max(i, j);}, INT_MIN);
  while(q--) {
    int type, x, y;
    scanf("%d%d%d", &type, &x, &y);
    x = n-x+1;
    if(type == 1) {
      seg.update(x-1, y);
    }
    if(type == 2) {
      y = n-y;
      printf("%d\n", seg.query(y, x));
    }
    if(type == 3) {
      printf("%d\n", n+1-seg.min_left(x, [y](int X)->bool{return X < y;}));
    }
  }
}