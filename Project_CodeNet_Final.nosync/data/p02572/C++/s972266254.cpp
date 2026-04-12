#include <bits/stdc++.h>
#include <unordered_map>
#pragma GCC optimize("Ofast")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimization ("unroll-loops")
#define Rep(i,a,b) for(int i = a; i <= b; ++i)
#define RepInv(i,a,b) for(int i = a; i >= b; --i)
#define rep(i,b) Rep(i,0,b-1)
#define fr first
#define sc second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define Yes(q) ((q) ? "Yes" : "No")
#define YES(q) ((q) ? "YES" : "NO")
#define Possible(q) ((q) ? "Possible" : "Impossible")
#define POSSIBLE(q) ((q) ? "POSSIBLE" : "IMPOSSIBLE")
#define int long long
using ll = long long;
using namespace std;
constexpr int inf = 1e9 + 7;
constexpr int mod = 1e9 + 7;
// 0~3??????? 4~7?????
//constexpr int dx[] = { 1, 0, -1, 0, 1, -1 };
//constexpr int dy[] = { 0, 1, 0, -1, 1, 1 };

struct r {
  double x, y;
  r() {}
  r(double _x, double _y) {
    x = _x;
    y = _y;
  }
  const bool operator == (r &a) {
    return a.x == x && a.y == y;
  }
};

istream& operator>>(istream &in, r &p) {
  in >> p.x >> p.y;
  return in;
}

ostream& operator<<(ostream &out, const r &p) {
  out << p.x << " " << p.y << '\n';
  return out;
}

template <typename T, typename U> ostream& operator << (ostream& in, const pair<T, U>& A) {
  in << A.first << " " << A.second;
  return in;
}
namespace {
  template<typename T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
  template<typename T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
  // ????
  void Write(long long x, const char* end = "\n") { std::cout << x << end; }
  template <typename T> void Write(const T& x, const char* end = "\n") { std::cout << x << end; }
  template <typename T, typename U> void Write(const T& x, const U& y, const char* end = "\n") { std::cout << x << " " << y << end; }
  template <typename T, typename U, typename V> void Write(const T& x, const U& y, const V& z, const char* end = "\n") { std::cout << x << " " << y << " " << z << end; }
  //template <typename... Args> void Write(Args const&... args) { bool a = true; for (auto const& x : { args... }) { if (a) a = false; else std::cout << " "; std::cout << x; } std::cout << "\n"; }
  template <typename T> void Write(const std::vector<T>& x, char* sep = " ", const char* end = "\n") { for (std::size_t i = 0, sz = x.size(); i < sz; ++i) { std::cout << x[i] << (i == sz - 1 ? end : sep); } }
  template <typename T> void Writeln(const std::vector<T>& x, char* sep = "\n", const char* end = "\n") { for (std::size_t i = 0, sz = x.size(); i < sz; ++i) { std::cout << x[i] << (i == sz - 1 ? end : sep); } }
  template <typename T> void Write(const std::vector<std::vector<T>>& x, const char* sep = " ", const char* end = "\n") { for (auto v : x) Write(v, sep, end); }

  struct Read {
    std::size_t szi, szj;
    Read(std::size_t _szi = 1, std::size_t _szj = 1) : szi(_szi), szj(_szj) {}
    template <typename T> operator T () const { T a; std::cin >> a; return a; }
    template <typename T> operator std::vector<T>() const { std::vector<T> a(szi); for (std::size_t i = 0; i < szi; ++i) std::cin >> a[i]; return a; }
    template <typename T> operator std::vector<std::vector<T>>() const {
      std::vector<std::vector<T>> a(szi, std::vector<T>(szj));
      for (std::size_t i = 0; i < szi; ++i) for (std::size_t j = 0; j < szj; ++j) cin >> a[i][j]; return a;
    }
    template <typename T, typename U> operator std::vector<std::pair<T, U>>() const {
      std::vector<std::pair<T, U>> a(szi);
      for (std::size_t i = 0; i < szi; ++i) std::cin >> a[i].first >> a[i].second; return a;
    }
  };
  struct Read1 {
    std::size_t szi, szj;
    Read1(std::size_t _szi = 1, std::size_t _szj = 1) : szi(_szi), szj(_szj) {}
    template <typename T> operator T () const { T a; std::cin >> a; return a; }
    template <typename T> operator std::vector<T>() const { std::vector<T> a(szi + 1); for (std::size_t i = 1; i <= szi; ++i) std::cin >> a[i]; return a; }
    template <typename T> operator std::vector<std::vector<T>>() const {
      std::vector<std::vector<T>> a(szi, std::vector<T>(szj));
      for (std::size_t i = 1; i <= szi; ++i) for (std::size_t j = 1; j <= szj; ++j) cin >> a[i][j]; return a;
    }
    template <typename T, typename U> operator std::vector<std::pair<T, U>>() const {
      std::vector<std::pair<T, U>> a(szi);
      for (std::size_t i = 1; i <= szi; ++i) std::cin >> a[i].first >> a[i].second; return a;
    }
  };

  template <typename T> void Reads(T& a) { std::cin >> a; }
  template <typename T, typename U> void Reads(T& a, U& b) { std::cin >> a >> b; }
  template <typename T, typename U, typename V> void Reads(T& a, U& b, V& c) { std::cin >> a >> b >> c; }
  template <typename T, typename U, typename V, typename W> void Reads(T& a, U& b, V& c, W& d) { std::cin >> a >> b >> c >> d; }
  Read read;
  Read1 read1;
}
double len(r a) {
  return hypot(a.x, a.y);
}

r operator+(r a, r b) { return r(a.x + b.x, a.y + b.y); }
r operator-(r a, r b) { return r(a.x - b.x, a.y - b.y); }
double operator*(r a, r b) { return a.x * b.x + a.y * b.y; }
double operator^(r a, r b) { return a.x * b.y - a.y * b.x; }
void testCase() {
  int n;
  Reads(n);
  vector<int> a = Read1(n);
  vector<int> p(n + 1);
  Rep(i, 1, n) {
    p[i] = (p[i - 1] + a[i]) % mod;
  }
  auto get = [&](int l, int r) {
    return (p[r] - p[l - 1] + mod) % mod;
  };
  int ans = 0;
  Rep(i, 1, n) {
    int add = (a[i] * get(i + 1, n)) % mod;
    ans = (ans + add) % mod;
  }
  Write(ans);
}
signed main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int q = 1;
  //Reads(q);
  while (q--)
    testCase();
}
/*2 3 4
5
3
2
1
2
1 1
1 2
2 2
2 3
ans = 13*/