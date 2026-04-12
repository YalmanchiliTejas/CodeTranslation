#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
const lli INF = 1LL<<60LL;

typedef lli T;
class SegmentTree {
private:
  int n;
  vector<T> dat_min, lazy_add;

public:
  SegmentTree() {}

  SegmentTree(int _n) {
    n = 1;
    while (n < _n) n *= 2;
    dat_min = lazy_add = vector<T>(n*2-1, 0);
  }

  inline void evaluation(int k, int l, int r) {
    dat_min[k] += lazy_add[k];
    if (k < n-1) {
      lazy_add[k*2+1] += lazy_add[k];
      lazy_add[k*2+2] += lazy_add[k];
    }
    lazy_add[k] = 0;
  }

  void add(int a, int b, T x, int k = 0, int l = 0, int r = -1) {
    if (r == -1) r = n;
    evaluation(k, l, r);
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
      lazy_add[k] += x;
      evaluation(k, l, r);
      return;
    }
    add(a, b, x, k*2+1, l, (l+r)/2);
    add(a, b, x, k*2+2, (l+r)/2, r);
    dat_min[k] = min(dat_min[k*2+1], dat_min[k*2+2]);
  }

  T mini(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) r = n;
    evaluation(k, l, r);
    if (r <= a || b <= l) return INF;
    if (a <= l && r <= b) return dat_min[k];
    T v1 = mini(a, b, k*2+1, l, (l+r)/2);
    T v2 = mini(a, b, k*2+2, (l+r)/2, r);
    return min(v1, v2);
  }
};


int main() {
  lli N;
  while (cin >> N) {
    vector<lli> S(N);
    for (lli i = 0; i < N; ++i) {
      cin >> S[i];
    }
    SegmentTree a(N/2), b(N/2);
    for (lli i = 0; i < N/2; ++i) {
      lli x = S[i] - S[N-i-1];
      a.add(i, i + 1, x);
      b.add(i, i + 1, -x);
    }
    const lli m = N/2;
    lli Q;
    cin >> Q;
    while (Q--) {
      lli l, r, x;
      cin >> l >> r >> x;
      --l; --r;
      if (l < m) {
        a.add(l, min(r+1, m), x);
        b.add(l, min(r+1, m), -x);
        //cout << "+[" << l << "," << min(r+1, m) << "] ";
      }
      if (m <= r) {
        a.add(N - r - 1, min(N/2, N - l), -x);
        b.add(N - r - 1, min(N/2, N - l), x);
        //cout << "-[" << N-r-1 << "," << min(N/2, N - l) << "]";
      }
      //cout << endl;
      if (a.mini(0, m) == 0 && b.mini(0, m) == 0) {
        cout << 1 << endl;
      } else {
        cout<<  0 << endl;
      }
    }
  }
  return 0;
}