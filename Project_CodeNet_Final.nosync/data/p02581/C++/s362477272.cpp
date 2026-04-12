#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
//const int mod = 998244353;

const int64 infll = (1LL << 62) - 1;
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
  vector< int > A(3 * N);
  cin >> A;
  for(auto &c : A) --c;
  A.emplace_back(N);
  A.emplace_back(N);

  auto dp = make_v< int >(N + 1, N + 1);
  auto dp2 = make_v< int >(N + 1);
  fill_v(dp2, -inf);
  fill_v(dp, -inf);

  dp[A[0]][A[1]] = 0;
  dp[A[1]][A[0]] = 0;
  chmax(dp2[A[0]], 0);
  chmax(dp2[A[1]], 0);

  int add = 0, pre_max = 0;
  vector< tuple< int, int, int > > upd;

  // 困りました.............

  for(int i = 0; i < 3 * N; i += 3) {

    vector< int > B{A[i + 2], A[i + 3], A[i + 4]};
    sort(begin(B), end(B));


    if(B[0] == B[2]) {
      ++add;
      continue;
    } else if(B[0] == B[1]) {

      // {B[0],B[1],a} -> {b, B[2]}
      for(int j = 0; j <= N; j++) upd.emplace_back(j, B[2], dp[j][B[0]] + 1);
      // {B[2],a,b}   -> {B[0],B[1]}
      upd.emplace_back(B[0], B[1], dp[B[2]][B[2]] + 1);

    } else if(B[1] == B[2]) {

      swap(B[0], B[2]);

      // {B[0],B[1],a} -> {b, B[2]}
      for(int j = 0; j <= N; j++) upd.emplace_back(j, B[2], dp[j][B[0]] + 1);
      // {B[2],a,b}   -> {B[0],B[1]}
      upd.emplace_back(B[0], B[1], dp[B[2]][B[2]] + 1);

    } else {
      upd.emplace_back(B[0], B[1], dp[B[2]][B[2]] + 1);
      upd.emplace_back(B[1], B[2], dp[B[0]][B[0]] + 1);
      upd.emplace_back(B[0], B[2], dp[B[1]][B[1]] + 1);
    }
    for(int j = 0; j <= N; j++) {
      upd.emplace_back(j, B[0], dp2[j]);
      upd.emplace_back(j, B[1], dp2[j]);
      upd.emplace_back(j, B[2], dp2[j]);
    }
    for(int j = 0; j < 3; j++) {
      for(int k = 0; k < 3; k++) {
        if(j != k) {
          chmax(dp[B[j]][B[k]], pre_max);

          chmax(dp2[B[j]], pre_max);
          chmax(dp2[B[k]], pre_max);
        }
      }
    }
    for(auto&[a, b, c] : upd) {
      chmax(dp[a][b], c);
      chmax(dp[b][a], c);

      chmax(pre_max, c);
      chmax(dp2[a], c);
      chmax(dp2[b], c);
    }
    upd.clear();
  }
  cout << pre_max + add << "\n";
}


