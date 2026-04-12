#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/*BigInteger
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/rational.hpp>
namespace xxx = boost::multiprecision;
using Bint = xxx::cpp_int;
using Real = xxx::number<xxx::cpp_dec_float<1024>>;
*/

#define int long long
#define pb(x) push_back(x)
#define m0(x) memset((x), 0, sizeof(x))
#define mm(x) memset((x), -1, sizeof(x))

//container
#define ALL(x) (x).begin(), (x).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define EACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define UNIQUE(v) (v).erase(unique((v).begin(), (v).end()), (v).end());
#define PERM(c) \
  sort(ALL(c)); \
  for (bool c##p = 1; c##p; c##p = next_permutation(ALL(c)))

// debug
#define GET_VAR_NAME(variable) #variable
#define test(x) cout << GET_VAR_NAME(x) << " = " << x << endl;

// bit_macro
#define bit(n) (1LL << (n))
#define bitset(a, b) (a) |= (1 << (b))
#define bitunset(a, b) (a) &= ~(1 << (b))
#define bitcheck(a, b) ((((a) >> (b)) & 1) == 1)
#define bitcount(a) __builtin_popcountll((a))

//typedef
typedef long long lint;
typedef unsigned long long ull;
typedef complex<long double> Complex;
typedef pair<int, int> P;
typedef tuple<int, int, int> TP;
typedef vector<int> vec;
typedef vector<vec> mat;

//constant
constexpr int INF = (int)1e18;
constexpr int MOD = (int)1e9 + 7;
constexpr double PI = (double)acos(-1);
constexpr double EPS = (double)1e-10;
constexpr int dx[] = {-1, 0, 0, 1, 0, -1, -1, 1, 1};
constexpr int dy[] = {0, -1, 1, 0, 0, 1, -1, 1, -1};

//
template <typename T>
void chmax(T &a, T b) { a = max(a, b); }
template <typename T>
void chmin(T &a, T b) { a = min(a, b); }
//
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}

//
struct Accelerate_Cin {
  Accelerate_Cin() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
  };
};

int dp[10100][110][2];

signed main() {
  string K;
  int D;
  cin >> K >> D;

  m0(dp);
  dp[0][0][0] = 1;

  for (int i = 0; i < K.size(); i++) {
    for (int j = 0; j < D; j++) {
      for (int f = 0; f < 2; f++) {

        if (f == 0) {
          for (int k = 0; k <= (K[i] - '0'); k++) {

            if (k < K[i] - '0') {
              dp[i + 1][(j + k) % D][1] += dp[i][j][0];
              dp[i + 1][(j + k) % D][1] %= MOD;

            } else {
              dp[i + 1][(j + k) % D][0] += dp[i][j][0];
              dp[i + 1][(j + k) % D][0] %= MOD;
            }
          }

        } else {
          for (int k = 0; k <= 9; k++) {
            dp[i + 1][(j + k) % D][1] += dp[i][j][1];
            dp[i + 1][(j + k) % D][1] %= MOD;
          }
        }
      }
    }
  }

  cout << ((dp[K.size()][0][0] + dp[K.size()][0][1]) % MOD - 1 + MOD) % MOD << endl;
  return 0;
}
