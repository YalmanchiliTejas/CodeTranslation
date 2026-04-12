#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
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

// ----- end of debug ---------

const int N = 200010;
vector<long long> tree(4 * N), lazy(4 * N);

void push_down(int lb, int rb, int v) {
  tree[2 * v] += lazy[v];
  tree[2 * v + 1] += lazy[v];
  lazy[2 * v] += lazy[v];
  lazy[2 * v + 1] += lazy[v];
  lazy[v] = 0;
}

long long query(int ql, int qr, int lb ,int rb, int v) {
  if (rb <= ql || qr <= lb) return 1e18;
  if (ql <= lb && rb <= qr) return tree[v];
  push_down(lb, rb, v);  
  int m = (lb + rb) / 2;
  return min(query(ql, qr, lb, m, 2 * v), query(ql, qr, m, rb, 2 * v + 1));
}

void add(int ql, int qr, long long w, int lb, int rb, int v) {
  if (rb <= ql || qr <= lb) {
    return;
  }
  if (ql <= lb && rb <= qr) {
    tree[v] += w;
    lazy[v] += w;
    return;
  }
  push_down(lb, rb, v);
  int m = (lb + rb) / 2;
  add(ql, qr, w, lb, m, 2 * v);
  add(ql, qr, w, m, rb, 2 * v + 1);
  tree[v] = min(tree[2 * v], tree[2 * v + 1]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;
  vector< vector< pair<int,int> > > intervals(n + 2);
  long long sum = 0;
  for (int i = 0; i < m; i++) {
    int l, r, w;
    cin >> l >> r >> w;
    sum += w;
    intervals[r].emplace_back(l, w);
  }

  vector<long long> dp(n + 2);
  for (int i = 1; i <= n + 1; i++) {
    dp[i] = query(0, i, 0, n + 2, 1);
    add(i, i + 1, dp[i], 0, n + 2, 1);
    for (auto seg : intervals[i]) {
      int l, w;
      tie(l, w) = seg;
      add(0, l, w, 0, n + 2, 1);
    }
  }
  debug(dp);
  cout << sum - dp[n + 1] << '\n';
  return 0;
}