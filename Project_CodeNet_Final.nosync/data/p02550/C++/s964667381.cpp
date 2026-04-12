#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr int MOD = 1000000007;
constexpr int INF = 1LL << 30;
constexpr long long LLINF = 1LL << 62;
constexpr double EPS = 1e-9;

struct Initializer {
  Initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(15) << boolalpha;
  }
} initializer;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "[";
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    if (it != vec.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}

template<typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &pa) {
  return os << "(" << pa.first << ", " << pa.second << ")";
}

template<typename Tuple, size_t N>
struct TuplePrinter {
  static void print(const Tuple &t) {
    TuplePrinter<Tuple, N-1>::print(t);
    cout << ", " << get<N-1>(t);
  }
};

template<typename Tuple>
struct TuplePrinter<Tuple, 1> {
  static void print(const Tuple &t) {
    cout << get<0>(t);
  }
};

template<typename... T>
ostream &operator<<(ostream &os, const tuple<T...> &tup) {
  os << "(";
  TuplePrinter<decltype(tup), sizeof...(T)>::print(tup);
  return os << ")";
}

template<typename T>
ostream &operator<<(ostream &os, const set<T> &se) {
  os << "{";
  for (auto it = se.begin(); it != se.end(); ++it) {
    if (it != se.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}

template<typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &ma) {
  os << "{";
  for (auto it = ma.begin(); it != ma.end(); ++it) {
    if (it != ma.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  return os << "}";
}

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }


int main() {
  long long n, x, m; cin>>n>>x>>m;
  unordered_set<long long> app1, app2;
  long long ans = 0;

  vector<long long> loop;
  int loop_start = -1, loop_cnt = 0;
  long long loop_sum = 0;

  for (long long i = 0; i < n; i++) {
    app1.emplace(x);
    ans += x;
    x = x * x;
    x %= m;
    if (app1.find(x) != app1.end()) {
      loop_start = i+1;
      break;
    }
  }

  if (loop_start != -1) {
    for (long long i = loop_start; i < n; i++) {
      loop.emplace_back(x);
      app2.emplace(x);
      loop_sum += x;
      ++loop_cnt;
      x = x * x;
      x %= m;
      if (app2.find(x) != app2.end()) {
        break;
      }
    }
  }

  if (loop_cnt != 0) {
    long long d = (n - loop_start) / loop_cnt;
    long long r = (n - loop_start) % loop_cnt;
    ans += loop_sum * d;
    rep(i, r) {
      ans += loop[i];
    }
  }

  print(ans);

  return 0;
}