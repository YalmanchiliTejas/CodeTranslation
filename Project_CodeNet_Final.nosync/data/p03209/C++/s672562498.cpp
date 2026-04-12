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
#define bitcheck(a, b) (((a) >> (b)) & 1)
#define bitcount(a) __builtin_popcountll((a))

//typedef
typedef long long lint;
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

int N, X;
int f[100], num[100];

int rec(int n, int pos) {
  if (pos == 0) return 0;
  if (n == 0) return 1;

  if (pos >= 2 * num[n - 1] + 2) {
    return f[n];
  } else if (pos >= num[n - 1] + 2) {
    int tmp = pos - (num[n - 1] + 2);
    int res = f[n - 1] + 1 + rec(n - 1, tmp);
    return res;
  } else {
    int tmp = pos - 1;
    return rec(n - 1, tmp);
  }
}

signed main() {
  cin >> N >> X;

  f[0] = num[0] = 1;
  for (int i = 0; i < 50; i++) {
    f[i + 1] = 2 * f[i] + 1;
    num[i + 1] = 2 * num[i] + 3;
  }

  cout << rec(N, X) << endl;
  return 0;
}
