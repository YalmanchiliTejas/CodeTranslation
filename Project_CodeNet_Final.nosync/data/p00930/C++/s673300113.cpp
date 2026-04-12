#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<28;

class SegmentTree {
private:
  int n;
  vector<int> dat1, dat2, lazy;

public:
  SegmentTree() {}

  SegmentTree(int _n) {
    n = 1;
    while (n < _n) n *= 2;
    dat1 = dat2 = lazy = vector<int>(n*2-1, 0);
  }

  inline void evaluation(int k, int l, int r) {
    dat1[k] += (r - l) * lazy[k];
    dat2[k] += lazy[k];
    if (k < n-1) {
      lazy[k*2+1] += lazy[k];
      lazy[k*2+2] += lazy[k];
    }
    lazy[k] = 0;
  }

  void add(int a, int b, int x, int k = 0, int l = 0, int r = -1) {
    if (r == -1) r = n;
    evaluation(k, l, r);
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
      lazy[k] += x;
      evaluation(k, l, r);
      return;
    }
    add(a, b, x, k*2+1, l, (l+r)/2);
    add(a, b, x, k*2+2, (l+r)/2, r);
    dat1[k] += dat1[k*2+1] + dat1[k*2+2];
    dat2[k] = min(dat2[k*2+1], dat2[k*2+2]);
  }

  int sum(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) r = n;
    evaluation(k, l, r);
    if (r <= a || b <= l) return 0;
    if (a <= l && r <= b) return dat1[k];
    int v1 = sum(a, b, k*2+1, l, (l+r)/2);
    int v2 = sum(a, b, k*2+2, (l+r)/2, r);
    return v1 + v2;
  }

  int mini(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) r = n;
    evaluation(k, l, r);
    if (r <= a || b <= l) return INF;
    if (a <= l && r <= b) return dat2[k];
    int v1 = mini(a, b, k*2+1, l, (l+r)/2);
    int v2 = mini(a, b, k*2+2, (l+r)/2, r);
    return min(v1, v2);
  }
};

int N, Q;
string s;
set<int> cs;
SegmentTree seg;

void init() {
  cs = set<int>();
  seg = SegmentTree(N);
  for (int i = 0; i < N; ++i) {
    if (s[i] == ')') cs.insert(i);
    seg.add(i, N, s[i] == '(' ? +1 : -1);
  }
}

void change(int index) {
  if (s[index] == '(') {
    s[index] = ')';
    seg.add(index, N, -2);
    cs.insert(index);
  } else {
    s[index] = '(';
    seg.add(index, N, +2);
    cs.erase(index);
  }
}

int main() {
  while (cin >> N >> Q) {
    cin >> s;
    init();
    while (Q--) {
      int q; cin >> q; --q;
      if (s[q] == '(') { // '(' => ')'
        change(q);
        int p = *cs.begin();
        cout << p + 1 << endl;
        change(p);
      } else { // ')' => '('
        change(q);
        int l = 0, r = N;
        while (r-l) {
          int m = (l + r) / 2;
          if (seg.mini(m, N) > 1) {
            r = m;
          } else {
            l = m+1;
          }
        }
        cout << r + 1 << endl;
        change(r);
      }
    }
  }
  return 0;
}