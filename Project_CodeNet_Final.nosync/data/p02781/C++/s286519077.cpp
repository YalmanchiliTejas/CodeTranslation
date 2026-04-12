#include <bits/stdc++.h>
using namespace std;

// #include <boost/algorithm/string/join.hpp>
// using boost::algorithm::join;
//
#include "boost/multi_array.hpp"
// boost::multi_array<int, 3> dp;
// dp.resize(boost::extents[10][9][8]);
//
// #include <boost/multiprecision/cpp_dec_float.hpp>  // quite slowly
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision; // mp::log10
// using bigint = boost::multiprecision::cpp_int;
// using rational = mp::cpp_rational;  // double d = static_cast<double>(r);

typedef long long ll;
typedef unsigned long long ull;
//typedef long double ld;

typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<double,double> pdd;
typedef set<int> si;
typedef set<ll> sll;
typedef vector<int> vi;
typedef vector<pair<int, int > > vii;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vll> vvll;

//constexpr ll MOD = 1e9+7;
template<typename T>constexpr auto inf=numeric_limits<T>::max()/4;
constexpr int INF=inf<int>;
constexpr ll LINF=inf<ll>;

#define Sort(x) sort(begin(x),end(x))
#define Reverse(x) reverse(begin(x),end(x))
#define ABS(a,b) ((a)<(b)?(b)-(a):(a)-(b))
#define nbit(n) (1ull<<(n))
#define _ol3(_1,_2,_3,name,...)name
#define _rep(i,n)_repi(i,0,n)
#define _repi(i,a,b)for(int i=a,i##_l=(b);i<i##_l;++i)
#define REP(...) _ol3(__VA_ARGS__,_repi,_rep,)(__VA_ARGS__)
#define REPR(i,n) for(int i=n-1;i>=0;--i)
#define REPA(i,v) REP(i,(v).size())

// sort(begin(x), end(x), greater<ll>());
// lower_bound(a.begin(), a.end(), val): a[i] ≥ valである最左の位置
// upper_bound(a.begin(), a.end(), val): a[i] > valである最左の位置

// Returns minimum of a and b.
// If a is less b, a is set to b.
template<typename T>
T chmin(T& a, T b) {
  if (a > b) {
    a = b;
  }
  return a;
}

// Returns maximum of a and b.
// If a is less b, a is set to b.
template<typename T>
T chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
  return a;
}

template <typename T>
void dumpContents(const T& v, const string& msg)
{
  cerr << "### " << msg << " ###\n";
  for (const auto& x : v) {
    cerr << x << " ";
  }
  cerr << endl;
}

struct before_main_function {
  before_main_function() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<setprecision(20)<<fixed;
#define endl "\n"
  }
} before_main_function;

// ========== end of template ==========

int main(int argc, char** argv) {
  string N;
  cin >> N;

  int K;
  cin >> K;

  boost::multi_array<ll, 3> dp;
  dp.resize(boost::extents[100+10][2][5]);

  dp[0][0][0] = 1;

  REP(i, N.size()) {
    const int t = N[i]-'0';

    REP(k, 4) {
      if (t==0) {
        // exact to eact
        dp[i+1][0][k]   += dp[i][0][k];   // 0
        // exact to less : nothing
        // less to less
        dp[i+1][1][k+1] += dp[i][1][k]*9; // 1 to 9
        dp[i+1][1][k]   += dp[i][1][k];   // 0
      } else {
        // exact to eact
        dp[i+1][0][k+1] += dp[i][0][k];       // t
        // exact to less
        dp[i+1][1][k+1] += dp[i][0][k]*(t-1); // 1 to t-1
        dp[i+1][1][k]   += dp[i][0][k];       // 0

        // less to less
        dp[i+1][1][k+1] += dp[i][1][k]*9; // 1-9
        dp[i+1][1][k]   += dp[i][1][k];   // 0
      }
    }
  }

  ll ret = dp[N.size()][0][K];
  ret += dp[N.size()][1][K];
  cout << ret << endl;
  return 0;
}

/* vim: set expandtab shiftwidth=2 softtabstop=2 : */
