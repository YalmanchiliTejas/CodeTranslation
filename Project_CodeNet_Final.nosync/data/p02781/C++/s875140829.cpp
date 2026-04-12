/**
 *    author:  zjsdut
 *    created: 2020/03/10 09:56:29
 **/
#include <bits/stdc++.h>

using namespace std;

struct fast_ios {
  fast_ios() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
  };
} fast_ios_;

template <typename A, typename B> bool chkmin(A &a, const B &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}

template <typename A, typename B> bool chkmax(A &a, const B &b) {
  if (b > a) {
    a = b;
    return true;
  }
  return false;
}

template <typename T> istream &operator>>(istream &stream, vector<T> &vec) {
  for (auto &x : vec)
    stream >> x;
  return stream;
}

void scan() {}

template <class T, class... Args> void scan(T &a, Args &... rest) {
  cin >> a;
  scan(rest...);
}

using ll = long long;
using vl = vector<ll>;
using vb = vector<bool>;
using vi = vector<int>;
using pii = pair<int, int>;
template <typename T> using vv = vector<vector<T>>;
#define rng(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define up(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define down(i, b, a) for (int i = int(b); i >= int(a); i--)
#define rep(n)                                                                 \
  for (int _iter_##n = 0, _num_##n = (int)n; _iter_##n < _num_##n; ++_iter_##n)
#define FOR(x, cont) for (const auto &x : cont)
#define For(x, cont) for (auto &x : cont)
#define all(x) begin(x), end(x)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ep emplace
#define SZ(x) (int)(x).size()
#define UNIQ(vec) (vec).erase(unique(all(vec)), end(vec))
#define LB(cont, x) int(lower_bound(all(cont), x) - begin(cont))
#define UB(cont, x) int(upper_bound(all(cont), x) - begin(cont))

template <typename T>
ostream &operator<<(ostream &stream, const vector<T> &vec) {
  if (!vec.empty()) {
    stream << vec[0];
    for (size_t i = 1; i != vec.size(); ++i)
      stream << ' ' << vec[i];
  }
  return stream;
}

template <typename T> void print(const vector<T> &t) { cout << t << '\n'; }

template <typename T> void print(const vector<vector<T>> &t) {
  for (const auto &row : t) {
    print(row);
  }
}

template <typename T> void print(const T &t) { cout << t << ' '; }

template <typename T, typename... Args>
void print(const T &t, const Args &... rest) {
  print(t);
  print(rest...);
}

template <typename T> void println(const T &t) { cout << t << '\n'; }

template <typename T, typename... Args>
void println(const T &t, const Args &... rest) {
  print(t);
  println(rest...);
}

// debug code by tourist
string to_string(const string &s) { return '"' + s + '"'; }

string to_string(const char *s) { return to_string((string)s); }

string to_string(bool b) { return (b ? "true" : "false"); }

template <typename A, typename B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A> string to_string(A v) {
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

template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#if defined LOCAL && !defined DUIPAI
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
#if defined LOCAL
  ifstream in("in.txt");
  cin.rdbuf(in.rdbuf());
#endif
  string n;
  int k;
  scan(n, k);
  int len = SZ(n);
  vi d(len);
  rng (i, 0, len) {
    d[i] = n[i] - '0';
  }
  auto power = [](int x, int y) {
    int res = 1;
    rep (y) {
      res *= x;
    }
    return res;
  };
  auto binom = [](int x, int y) {
    int ans = 1;
    rng (i, 0, y) {
      ans *= x - i;
    }
    down (i, y, 2) {
      ans /= i;
    }
    return ans;
  };
  function<int(int, int)> calc = [&](int pos, int num) {
    if (num == 0) return 1;
    while (pos < len && d[pos] == 0) ++pos;
    if (pos == len) return 0;
    int res = (d[pos] - 1) * binom(len - pos - 1, num - 1) * power(9, num - 1);
    if (pos != 0) {
      res += binom(len - pos - 1, num) * power(9, num);
    }
    return res + calc(pos + 1, num - 1);
  };
  ll ans = 0;
  rng (i, k, len) {
    ans += binom(i - 1, k - 1);
  }
  ans *= power(9, k);
  debug(ans);
  println(ans + calc(0, k));
  return 0;
}