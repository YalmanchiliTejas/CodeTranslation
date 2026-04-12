/**
 *    author:  zjsdut
 *    created: 2020/01/20 06:26:43
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

template<typename A, typename B>
bool chkmin(A &a, const B &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}

template<typename A, typename B>
bool chkmax(A &a, const B &b) {
  if (b > a) {
    a = b;
    return true;
  }
  return false;
}

template<typename T>
istream &operator>>(istream &stream, vector<T> &vec) {
  for (auto &x : vec) stream >> x;
  return stream;
}

void scan() {}

template<class T, class ...Args>
void scan(T &a, Args &...rest) {
  cin >> a;
  scan(rest...);
}

using ll = long long;
using vl = vector<ll>;
using vb = vector<bool>;
using vi = vector<int>;
using pii = pair<int, int>;
template<typename T> using vv = vector<vector<T>>;
#define rng(i, a, b) for(int i = (int)(a); i < (int)(b); ++i)
#define up(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define down(i, b, a) for (int i = int(b); i >= int(a); i--)
#define rep(n) for(int _iter_##n = 0, _num_##n = (int)n; _iter_##n < _num_##n; ++_iter_##n)
#define FOR(x, cont) for (const auto &x: cont)
#define For(x, cont) for (auto &x: cont)
#define all(x) begin(x), end(x)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ep emplace
#define SZ(x) (int)(x).size()
#define UNIQ(vec) (vec).erase(unique(all(vec)), end(vec))
#define LB(cont, x) int(lower_bound(all(cont), x) - begin(cont))
#define UB(cont, x) int(upper_bound(all(cont), x) - begin(cont))

template<typename T>
ostream &operator<<(ostream &stream, const vector<T> &vec) {
  if (!vec.empty()) {
    stream << vec[0];
    for (size_t i = 1; i != vec.size(); ++i)
      stream << ' ' << vec[i];
  }
  return stream;
}

template<typename T>
void print(const vector<T> &t) { cout << t << '\n'; }

template<typename T>
void print(const vector<vector<T>> &t) {
  for (const auto &row : t) {
    print(row);
  }
}

template<typename T>
void print(const T &t) { cout << t << ' '; }

template<typename T, typename ...Args>
void print(const T &t, const Args &...rest) {
  print(t);
  print(rest...);
}

template<typename T>
void println(const T &t) { cout << t << '\n'; }

template<typename T, typename ...Args>
void println(const T &t, const Args &...rest) {
  print(t);
  println(rest...);
}

int main() {
#if defined LOCAL
  ifstream in("in.txt");
  cin.rdbuf(in.rdbuf());
#endif
  int n,m;
  scan(n, m);
  println(n == m ? "Yes" : "No");
  return 0;
}