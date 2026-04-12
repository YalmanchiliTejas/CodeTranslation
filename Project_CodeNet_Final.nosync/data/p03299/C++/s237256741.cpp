/**
 *    author:  tourist
 *    created: 14.07.2018 16:07:03       
**/
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

const int md = (int) 1e9 + 7;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}

inline int mul(int a, int b) {
#if !defined(_WIN32) || defined(_WIN64)
  return (int) ((long long) a * b % md);
#endif
  unsigned long long x = (long long) a * b;
  unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
  asm(
    "divl %4; \n\t"
    : "=a" (d), "=d" (m)
    : "d" (xh), "a" (xl), "r" (md)
  );
  return m;
}

inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int a) {
  a %= md;
  if (a < 0) a += md;
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}

// (chess, not)

pair<int,int> solve(vector<int> a) {
  int n = (int) a.size();
  int mn = *min_element(a.begin(), a.end());
  vector<int> b(n);
  int zeros = 0;
  for (int i = 0; i < n; i++) {
    b[i] = a[i] - mn;
    zeros += (b[i] == 0);
  }
  if (zeros == n) {
    int ans = md - 2;
    add(ans, power(2, n));
    auto res = make_pair(power(2, mn), ans);
    debug(a, res.first, res.second);
    return res;
  }
  vector<vector<int>> children;
  int beg = 0;
  while (beg < n) {
    if (b[beg] == 0) {
      beg++;
      continue;
    }
    int end = beg;
    while (end + 1 < n && b[end + 1] > 0) {
      end++;
    }
    vector<int> c;
    for (int i = beg; i <= end; i++) {
      c.push_back(b[i]);
    }
    children.push_back(c);
    beg = end + 1;
  }
  vector<pair<int,int>> aux;
  for (auto &v : children) {
    aux.push_back(solve(v));
  }
  int chess = 1;
  for (auto &p : aux) {
    chess = mul(chess, p.first);
  }
  chess = mul(chess, 2);
  int nott = 1;
  for (auto &p : aux) {
    int cur = mul(p.first, 2);
    add(cur, p.second);
    nott = mul(nott, cur);
  }
  nott = mul(nott, power(2, zeros));
  sub(nott, chess);
  chess = mul(chess, power(2, mn - 1));
  debug(a, chess, nott);
  return make_pair(chess, nott);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  pair<int,int> p = solve(a);
  cout << (p.first + p.second) % md << '\n';
  return 0;
}
