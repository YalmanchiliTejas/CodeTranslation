#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

//
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
#define bitunset(a, b) (a) |= ~(1 << (b))
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
const int INF = (int)1e18;
const int MOD = (int)1e9 + 7;
const double EPS = (double)1e-10;
const int dx[] = {-1, 0, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, -1, 1, 0, 0, 1, -1, 1, -1};

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

int N;
vec a;

int dp[3030][3030];

int rec(int l, int r, int turn) {
  if (dp[l][r] != INF) return dp[l][r];
  if (r < l || r == -1 || l == N) return 0;

  int res;
  if (turn == 0) {
    res = max(rec(l, r - 1, (turn + 1) % 2) + a[r], rec(l + 1, r, (turn + 1) % 2) + a[l]);
  } else {
    res = min(rec(l, r - 1, (turn + 1) % 2) - a[r], rec(l + 1, r, (turn + 1) % 2) - a[l]);
  }

  return dp[l][r] = res;
}

signed main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    a.pb(tmp);
  }

  for (int i = 0; i <= 3000; i++) {
    for (int j = 0; j <= 3000; j++) {
      dp[i][j] = INF;
    }
  }

  cout << rec(0, N - 1, 0) << endl;
  return 0;
}
