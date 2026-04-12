#include <bits/stdc++.h>
using namespace std;

template <typename T, T (*op)(T, T), T (*e)()>
struct segtree {
  segtree() : segtree(0) {}
  segtree(int n) : segtree(vector<T>(n, e())) {}
  segtree(vector<T> &v) : _n((int)v.size()) {
    log = 0;
    size = 1;
    while (size < _n) {
      size <<= 1;
      log++;
    }
    d = vector<T>(2 * size, e());
    for (int i = 0; i < _n; i++) {
      d[size + i] = v[i];
    }
    for (int i = size - 1; i >= 1; i--) {
      update(i);
    }
  }

  void set(int p, T x) {
    assert(0 <= p && p < _n);
    p += size;
    d[p] = x;
    for (int i = 1; i <= log; i++) {
      update(p >> i);
    }
  }

  T prod(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    T sml = e(), smr = e();
    for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
      if ((l & 1) == 1) {
        sml = op(sml, d[l++]);
      }
      if ((r & 1) == 1) {
        smr = op(d[--r], smr);
      }
    }
    return op(sml, smr);
  }

  template <bool (*f)(T)>
  int max_right(int l) {
    return max_right(l, [](T x) { return f(x); });
  }

  template <typename F>
  int max_right(int l, F f) {
    assert(0 <= l && l <= _n);
    assert(f(e()));
    if (l == _n) {
      return _n;
    }
    l += size;
    T sm = e();
    do {
      for (; (l & 1) == 0; l >>= 1) {
      }
      if (!f(op(sm, d[l]))) {
        while (l < size) {
          l = 2 * l;
          if (f(op(sm, d[l]))) {
            sm = op(sm, d[l]);
            l++;
          }
        }
        return l - size;
      }
      sm = op(sm, d[l]);
      l++;
    } while ((l & -l) != l);
    return _n;
  }

 private:
  int _n, size, log;
  vector<T> d;

  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

int op(int a, int b) { return max(a, b); }

int e() { return -1; }

int target;

bool f(int v) { return v < target; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  segtree<int, op, e> seg(a);
  while (q--) {
    int ti;
    cin >> ti;
    if (ti == 1) {
      int xi, vi;
      cin >> xi >> vi;
      xi--;
      seg.set(xi, vi);
    } else if (ti == 2) {
      int li, ri;
      cin >> li >> ri;
      li--;
      cout << seg.prod(li, ri) << '\n';
    } else {
      int xi;
      cin >> xi >> target;
      xi--;
      cout << seg.max_right<f>(xi) + 1 << '\n';
    }
  }
  return 0;
}