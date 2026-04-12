/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            pass System Test!
*/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
  if (!v.empty()) {
    out << '[';
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}
template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &p) {
  out << "[" << p.first << ", " << p.second << "]";
  return out;
}
template <class T, class U>
void chmin(T &t, U f) {
  if (t > f) t = f;
}
template <class T, class U>
void chmax(T &t, U f) {
  if (t < f) t = f;
}

struct StarrySkyTree {
  static const int N = 1 << 20;

  vector<long long> seg_min, seg_max, seg_add;
  StarrySkyTree()
      : seg_min(N * 2, (long long)1e18),
        seg_max(N * 2, -1e18),
        seg_add(N * 2, 0) {}

  // Add x to [a, b)
  void add(int a, int b, int x, int k = 0, int l = 0, int r = N) {
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
      seg_add[k] += x;
      while (k) {
        k = (k - 1) / 2;
        seg_min[k] = min(seg_min[k * 2 + 1] + seg_add[k * 2 + 1],
                         seg_min[k * 2 + 2] + seg_add[k * 2 + 2]);
        seg_max[k] = max(seg_max[k * 2 + 1] + seg_add[k * 2 + 1],
                         seg_max[k * 2 + 2] + seg_add[k * 2 + 2]);
      }
      return;
    }
    add(a, b, x, k * 2 + 1, l, (l + r) / 2);
    add(a, b, x, k * 2 + 2, (l + r) / 2, r);
  }

  void update(int k, long long value) {
    k += N - 1;
    seg_min[k] = value;
    seg_max[k] = value;
    while (k > 0) {
      k = (k - 1) / 2;
      seg_min[k] = min(seg_min[k * 2 + 1], seg_min[k * 2 + 2]);
      seg_max[k] = max(seg_max[k * 2 + 1], seg_max[k * 2 + 2]);
    }
  }

  //[a, b)
  long long get_min(int a, int b, int k = 0, int l = 0, int r = N) {
    if (r <= a || b <= l) return 1e18;
    if (a <= l && r <= b) return (seg_min[k] + seg_add[k]);
    long long x = get_min(a, b, k * 2 + 1, l, (l + r) / 2);
    long long y = get_min(a, b, k * 2 + 2, (l + r) / 2, r);
    return (min(x, y) + seg_add[k]);
  }

  //[a, b)
  long long get_max(int a, int b, int k = 0, int l = 0, int r = N) {
    if (r <= a || b <= l) return -1e18;
    if (a <= l && r <= b) return (seg_max[k] + seg_add[k]);
    long long x = get_max(a, b, k * 2 + 1, l, (l + r) / 2);
    long long y = get_max(a, b, k * 2 + 2, (l + r) / 2, r);
    return (max(x, y) + seg_add[k]);
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> S(N);
  for (int i = 0; i < N; ++i) cin >> S[i];
  for (int i = 0; i < N / 2; ++i) {
    S[N - 1 - i] -= S[i];
    S[i] = 0;
  }
  StarrySkyTree sst;
  for (int i = 0; i < N; ++i) sst.update(i, S[i]);

  int Q;
  cin >> Q;
  while (Q--) {
    int l, r, x;
    cin >> l >> r >> x;
    if (l <= N / 2 && N / 2 <= r) {
      int lw = N / 2 - l + 1;
      int rw = r - N / 2;
      if (lw > rw) {
        r = N / 2 - rw;
      } else if (lw < rw) {
        l = N / 2 + 1 + lw;
      } else {
        goto print;
      }
    }
    l--, r--;
    if (r < N / 2) {
      l = N - 1 - l;
      r = N - 1 - r;
      swap(l, r);
      x = -x;
    }
    // cout << l << " " << r << " " << x << endl;
    sst.add(l, r + 1, x);

  print:
    // for (int i = 0; i < N; ++i) cout << sst.get_min(i, i + 1) << " ";
    // cout << endl;
    // cerr << sst.get_max(0, N) << " " << sst.get_min(0, N) << endl;
    if (sst.get_max(0, N) == sst.get_min(0, N)) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }
}