#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct LazySegmentTree {
  vector<long long> data, lazy;
  int n;
  long unit = -(1<<30);

  LazySegmentTree(int n_) {
    for(n = 1; n < n_; n *= 2);
    data.assign(n*2 - 1, unit);
    lazy.assign(n*2 - 1, 0);
  }

  void propagate(int i, int l, int r) {
    if(data[i] == unit) data[i] = 0;

    if(lazy[i] != 0) {
      data[i] += lazy[i];

      if(r - l > 1) {
        lazy[i*2+1] += lazy[i];
        lazy[i*2+2] += lazy[i];
      }
    }

    lazy[i] = 0;
  }

  void update(int a, int b, long long x, int i = 0, int l = 0, int r = -1) {
    if(r < 0) r = n;

    propagate(i, l, r);

    if(b <= l || r <= a) return;
    if(a <= l && r <= b) {
      lazy[i] += x;
      propagate(i, l, r);
    } else {
      update(a, b, x, i*2+1, l, (l+r)/2);
      update(a, b, x, i*2+2, (l+r)/2, r);
      data[i] = max(data[i*2+1], data[i*2+2]);
    }
  }

  long long query(int a,int b,int i = 0,int l = 0, int r = -1) {
    if(r < 0) r = n;
    if(b <= l || r <= a) return unit;

    propagate(i, l, r);
    if(a <= l && r <= b) return data[i];
    long long vl = query(a, b, i*2+1, l, (l+r)/2);
    long long vr = query(a, b, i*2+2, (l+r)/2, r);
    return max(vl, vr);
  }
};

long n, m, l, r, a;
#define left first
#define score second
vector<pair<long, long>> intervals[200010];

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for(int i = 0; i < m; ++i) {
    cin >> l >> r >> a;
    intervals[r].emplace_back(l, a);
  }
  LazySegmentTree dp(n + 1);

  for(int i = 1; i <= n; ++i) {
    dp.update(i, i + 1, dp.query(0, i));
    for(auto itv: intervals[i]) {
      dp.update(itv.left, i + 1, itv.score);
    }
  }
  cout << dp.query(0, n + 1);
  return 0;
}