#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(i64 (i) = (s);(i) < (e);(i)++)
#define all(x) x.begin(),x.end()
#define STRINGIFY(n) #n
#define TOSTRING(n) STRINGIFY(n)
#define PREFIX "#" TOSTRING(__LINE__) "| "
#define debug(x) \
{ \
  std::cout << PREFIX << #x << " = " << x << std::endl; \
}

std::ostream& output_indent(std::ostream& os, int ind) {
  for(int i = 0; i < ind; i++) os << " ";
  return os;
}

template<class S, class T> std::ostream& operator<<(std::ostream& os, const std::pair<S, T>& p);
template<class T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& v);

template<class S, class T> std::ostream& operator<<(std::ostream& os, const std::pair<S, T>& p) {
  return (os << "(" << p.first << ", " << p.second << ")");
}
template<class T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
  os << "[";
  for(int i = 0;i < v.size();i++) os << v[i] << ", ";
  return (os << "]");
}

template<class T>
static inline std::vector<T> ndvec(size_t&& n, T val) { return std::vector<T>(n, std::forward<T>(val)); }
template<class... Tail>
static inline auto ndvec(size_t&& n, Tail&&... tail) {
  return std::vector<decltype(ndvec(std::forward<Tail>(tail)...))>(n, ndvec(std::forward<Tail>(tail)...));
}
template<class Cond> struct chain {
  Cond cond; chain(Cond cond) : cond(cond) {}
  template<class T> bool operator()(T& a, const T& b) const { if(cond(a, b)) { a = b; return true; } return false; }
};
template<class Cond> chain<Cond> make_chain(Cond cond) { return chain<Cond>(cond); }

#include <iostream>
using i64 = long long;
template<i64 M> struct modint { i64 a;
  constexpr modint(const i64 x = 0): a((x%M+M)%M){}
  constexpr i64 value() const { return a; }
  constexpr modint inv() const { return this->pow(M-2); }
  constexpr modint pow(i64 r) const {
    modint ans(1); modint aa = *this;
    while(r) { if(r & 1) ans *= aa; aa *= aa; r >>= 1; }
    return ans;
  }
  constexpr modint& operator=(const i64 r) { a = (r % M + M) % M; return *this; }
  constexpr modint& operator+=(const modint r) { a += r.a; if(a >= M) a -= M; return *this; }
  constexpr modint& operator-=(const modint r) { a -= r.a; if(a < 0) a += M; return *this; }
  constexpr modint& operator*=(const modint r) { a = a * r.a % M; return *this; }
  constexpr modint& operator/=(const modint r) { (*this) *= r.inv(); return *this; }
  constexpr modint operator+(const modint r) const { return modint(*this) += r; }
  constexpr modint operator-(const modint r) const { return modint(*this) -= r; }
  constexpr modint operator*(const modint r) const { return modint(*this) *= r; }
  constexpr modint operator/(const modint r) const { return modint(*this) /= r; }
  constexpr bool operator!=(const modint r) const { return this->value() != r.value(); }
};

template<const i64 M> std::ostream& operator<<(std::ostream& os, const modint<M>& m) { os << m.value(); return os; }

using fp = modint<998244353>;

int main() {
  i64 N, X, M;
  cin >> N >> X >> M;
  std::vector<i64> start(101010, -1);
  std::vector<i64> vs;
  int bg;
  i64 now = X;
  {
    while(true) {
      if(start[now] == -1) {
        start[now] = vs.size();
        vs.push_back(now);
      }
      else {
        bg = start[now];
        break;
      }
      now = (now * now) % M;
    }
  }
  i64 ans = 0;
  if(N < bg) {
    ans = std::accumulate(std::begin(vs), std::begin(vs) + N, 0ll);
  }
  else {
    i64 len = vs.size() - bg;
    i64 time = (N - bg) / len;
    i64 rem = (N - bg) % len;
    i64 before = std::accumulate(std::begin(vs), std::begin(vs) + bg, 0ll);
    i64 sum = std::accumulate(std::begin(vs) + bg, std::end(vs), 0ll);
    ans = before + sum * time + std::accumulate(std::begin(vs) + bg, std::begin(vs) + bg + rem, 0ll);
  }
  cout << ans << endl;
}
