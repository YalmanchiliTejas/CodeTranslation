#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 998244353;

const int64 infll = (1LL << 60) - 1;
const int inf = (1 << 30) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;


template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 > &p) {
  os << p.first << " " << p.second;
  return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second;
  return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in : v) is >> in;
  return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template< typename T = int64 >
vector< T > make_v(size_t a) {
  return vector< T >(a);
}

template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

template< typename T, typename V >
typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {
  t = v;
}

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
  for(auto &e : t) fill_v(e, v);
}

template< typename F >
struct FixPoint : F {
  FixPoint(F &&f) : F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector< int > A((1 << N) * 2);
  for(int i = 0; i < (1 << N); i++) cin >> A[i];
  for(int i = 0; i < (1 << N); i++) A[i + (1 << N)] = A[i];
  auto dp = make_v< int >(N + 1, (1 << N) * 2);
  fill_v(dp, -1);
  for(int i = 0; i < A.size(); i++) {
    dp[0][i] = A[i];
  }
  auto choose = [&](int x, int y) {
    if(x == -1) return y;
    if(y == -1) return x;
    if(x > y) swap(x, y);
    if(S[y - x - 1] == '1') return y;
    return x;
  };
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < A.size(); j++) {
      if(dp[i][j] == -1) continue;
      if(j + (1 << i) < A.size()) {
        int u = dp[i][j];
        int v = dp[i][j + (1 << i)];
        dp[i + 1][j] = choose(u, v);
      }
    }
  }
  for(int i = 0; i < (1 << N); i++) {
    cout << dp[N][i] << "\n";
  }
}

