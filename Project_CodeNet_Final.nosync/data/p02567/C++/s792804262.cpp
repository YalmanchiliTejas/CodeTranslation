#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

class SegmentTree {
  vector<long long> dat;
  int n = 1;
  long long def;
public:
  SegmentTree(int num, long long d) : def(d) {
    while (n < num)
      n <<= 1;
    dat.resize(2 * n - 1, def);
  }
  void update(int i, long long x) {
    i += (n - 1);
    dat[i] = x;
    while (i > 0) {
      i = (i - 1) / 2;
      dat[i] = max(dat[2 * i + 1], dat[2 * i + 2]);
    }
  }
  long long query(int a, int b, int i = 0, int li = 0, int ri = -1) {
    if (!i) ri = n;
    if (ri <= a || li >= b) return def;
    if (li >= a && ri <= b) return dat[i];
    long long vl = query(a, b, 2 * i + 1, li, (li + ri) / 2);
    long long vr = query(a, b, 2 * i + 2, (li + ri) / 2, ri);
    return max(vl, vr);
  }
  int upper_left(int a, int b, long long x, int i = 0, int li = 0, int ri = -1) {
    if (!i) ri = n;
    if (dat[i] < x || ri <= a || li >= b) return b;
    if (ri - li == 1) return li;
    int vl = upper_left(a, b, x, 2 * i + 1, li, (li + ri) / 2);
    if (vl < b)
      return vl;
    return upper_left(a, b, x, 2 * i + 2, (li + ri) / 2, ri);
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  SegmentTree st(n, 0);
  rep(i, n) {
    int a;
    cin >> a;
    st.update(i, a);
  }
  rep(_, q) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, v;
      cin >> x >> v;
      --x;
      st.update(x, v);
    }
    else if (t == 2) {
      int l, r;
      cin >> l >> r;
      --l;
      cout << st.query(l, r) << '\n';
    }
    else {
      int l, v;
      cin >> l >> v;
      --l;
      cout << st.upper_left(l, n, v)+1 << '\n';
    }
  }
  return 0;
}