/*
 *    author:  Gary Shih
 *    created: 2020-05-08 15:28:29
 */
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

// Debug {{{
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string)s); }

string to_string(bool b) { return (b ? "true" : "false"); }

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
// }}}

class SegmentTree {
 public:
  int n;
  vector<long long> node, tag;

  SegmentTree(int _n) : n(_n) {
    node.resize((n + 1) << 2);
    tag.resize((n + 1) << 2);
    debug(node.size());
    debug(tag.size());
  }

  void Push(int now, int l, int r) {
    if (l == r || (tag[now] == 0)) return;
    node[now * 2] += tag[now];
    tag[now * 2] += tag[now];
    node[now * 2 + 1] += tag[now];
    tag[now * 2 + 1] += tag[now];
    tag[now] = 0;
  }

  void Pull(int now, int l, int r) {
    if (l == r) return;
    node[now] = max(node[now * 2], node[now * 2 + 1]);
  }

  void Update(long long v, int ql, int qr) { Update(v, ql, qr, 1, 0, n); }

  void Update(long long v, int ql, int qr, int now, int l, int r) {
    debug(v, ql, qr, now, l, r);
    Push(now, l, r);
    if (ql == l && qr == r) {
      debug("Update");
      tag[now] += v;
      node[now] += v;
      return;
    }
    int mid = (l + r) >> 1;
    if (qr <= mid) {
      Update(v, ql, qr, now * 2, l, mid);
    } else if (mid + 1 <= ql) {
      Update(v, ql, qr, now * 2 + 1, mid + 1, r);
    } else {
      Update(v, ql, mid, now * 2, l, mid);
      Update(v, mid + 1, qr, now * 2 + 1, mid + 1, r);
    }
    Pull(now, l, r);
  }

  long long Query(int ql, int qr) { return Query(ql, qr, 1, 0, n); }

  long long Query(int ql, int qr, int now, int l, int r) {
    debug("Query", ql, qr, now, l, r);
    Push(now, l, r);
    if (ql == l && qr == r) return node[now];
    int mid = (l + r) >> 1;
    if (qr <= mid) {
      return Query(ql, qr, now * 2, l, mid);
    } else if (mid + 1 <= ql) {
      return Query(ql, qr, now * 2 + 1, mid + 1, r);
    } else {
      long long lChild = Query(ql, mid, now * 2, l, mid);
      long long rChild = Query(mid + 1, qr, now * 2 + 1, mid + 1, r);
      return max(lChild, rChild);
    }
  }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.setf(ios::fixed), cout.precision(9);
  int n, m;
  cin >> n >> m;
  vector<int> l(m), r(m), a(m);
  for (int i = 0; i < m; ++i) cin >> l[i] >> r[i] >> a[i];

  vector<vector<int>> lMap(n + 1), rMap(n + 1);
  for (int i = 0; i < m; ++i) {
    lMap[l[i]].push_back(i);
    rMap[r[i]].push_back(i);
  }

  debug(lMap);
  debug(rMap);

  SegmentTree st(n);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    debug(i);
    for (int j : rMap[i - 1]) st.Update(-a[j], 0, l[j] - 1);
    for (int j : lMap[i]) st.Update(a[j], 0, l[j] - 1);
    long long now = st.Query(0, i - 1);
    debug(now);
    ans = max(ans, now);
    debug("self");
    st.Update(now, i, i);
    debug("done");
  }
  for (int i = 0; i <= n; ++i) {
    long long now = st.Query(i, i);
  }
  debug("here");
  cout << ans << '\n';
  debug("end");
}
