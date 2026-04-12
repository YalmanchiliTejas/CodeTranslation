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

signed main() {
  int H, W;
  cin >> H >> W;

  char c[10][10];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      c[i][j] = '.';
    }
  }

  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> c[i][j];
    }
  }

  if (c[1][1] == '.') {
    cout << "Impossible" << endl;
    return 0;
  }

  for (int bit = 0; bit < bit(H + W - 2); bit++) {
    bool flag = true;
    int h = 1, w = 1;

    char cc[10][10];
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        cc[i][j] = c[i][j];
      }
    }
    cc[1][1] = '.';

    for (int i = 0; i < H + W - 2; i++) {
      if (bitcheck(bit, i)) {
        h++;
        if (c[h][w] == '.') {
          flag = false;
          break;
        }
      } else {
        w++;
        if (c[h][w] == '.') {
          flag = false;
          break;
        }
      }
      cc[h][w] = '.';
    }

    for (int i = 1; i <= H; i++) {
      if (flag == false) break;
      for (int j = 1; j <= W; j++) {
        if (cc[i][j] == '#') {
          flag = false;
          break;
        }
      }
    }

    if (flag) {
      cout << "Possible" << endl;
      return 0;
    }
  }

  cout << "Impossible" << endl;
  return 0;
}
