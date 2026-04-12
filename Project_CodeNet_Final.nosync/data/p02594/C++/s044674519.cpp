#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
#define int ll

const ll MOD = 1000000007;
const ll INF_LL = (ll)1000000007 * 1000000007;
const int INF_INT = (int)1000000007;
const double PI = 3.14159265358979323846;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define irep(itr, st) for (auto itr = (st).begin(); itr != (st).end(); ++itr)
#define irrep(itr, st) for (auto itr = (st).rbegin(); itr != (st).rend(); ++itr)

#define m0(x) memset((x), 0, sizeof((x)))
#define m1(x) memset((x), -1, sizeof((x)))

// xにはvectorなどのコンテナ
#define ALL(x) (x).begin(), (x).end()  // sortなどの引数を省略したい
#define RALL(x) (x).rbegin(), (x).rend()  // sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size())     // sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x))  //最大値を求める
#define MIN(x) *min_element(ALL(x))  //最小値を求める
#define all(x) (x).begin(), (x).end()

//略記
#define pb emplace_back  // vectorヘの挿入
#define mp make_pair     // pairのコンストラクタ
#define F first          // pairの一つ目の要素
#define S second         // pairの二つ目の要素

#define BITCOUNT __builtin_popcount
#define BITCOUNT_LL(x) __builtin_popcountll(x)

#define perm(c)             \
  sort(all(c));             \
  for (bool c##p = 1; c##p; \
       c##p = next_permutation(all(c)))  //順列 123 132 213 231 312 321

#define BIT(n) (1LL << (n))

#ifdef DEBUG
#define PRINT(A) std::cout << (#A) << ": " << (A) << std::endl;
#else
#define PRINT(A)
#endif

//入力高速化
struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

signed main() {
  int X; cin >> X;
  if(X >= 30){
    cout << "Yes" << endl;
  }
  else{
        cout << "No" << endl;
  }
}