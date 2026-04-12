#include <bits/stdc++.h>

//{ START
using namespace std;
#define int int64_t
#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define reps(i, a, n) for (int i = (n - 1); i > (a - 1); --i)
#define arep(i, x) for (auto &&i : (x))
#define irep(i, x) for (auto i = (x).begin(); i != (x).end(); ++i)
#define rirep(i, x) for (auto i = (x).rbegin(); i != (x).rend(); ++i)
//降順はgreater<T>()
#define all(x) (x).begin(), (x).end()
#define rv(s) reverse((s).begin(), (s).end())
// gcd lcmはそのままok
#define gcd(a, b) __gcd(a, b)
#define bits(n) (1LL << (n))
#define pcnt(x) __builtin_popcountll(x)
//配列内等要素削除
#define Unique(x) (x).erase(unique((x).begin(), (x).end()), (x).end())
#define Fixed(n) fixed << setprecision(n)
//総和
#define sowa(n) (((n) * ((n) + 1)) / 2)
#define updiv(a, b) ((a + b - 1) / b)
#define cauto const auto &
using P = pair<int, int>;
using Graph = vector<vector<P>>;
template <class T>  //昇順
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <class T>  //降順
using max_heap = priority_queue<T>;
template <class A, class B>
using umap = unordered_map<A, B>;
template <class A>
using uset = unordered_set<A>;
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {  //多次元初期化
  std::fill((T *)array, (T *)(array + N), val);
}
template <class A, class B>
bool chmax(A &a, const B &b) {  //最大値更新 返り値はbool
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class A, class B>
bool chmin(A &a, const B &b) {  //最小値更新 返り値はbool
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, 1, -1, -1};
constexpr int INF = 0x3f3f3f3f;
constexpr int LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int mod1 = 1e9 + 7;
constexpr int mod2 = 998244353;
//} END

/*
BIT(sz) : 長さszの0で初期化された配列を構築する
BIT(vs) : 配列vsで構築する
add(k,x) : 要素kに値xを加える
query(k) : 区間[0,k]の総和を求める
lower_bound(x) : 区間[0,k]の総和がx以上となる最小のkを返す
upper_bound(x) : 区間[0,k]の総和がxを上回る最小のkを返す
*/
template <typename T>
struct BIT {
  vector<T> data;

  BIT() = default;

  explicit BIT(size_t sz) : data(sz + 1, 0) {}

  explicit BIT(const vector<T> &vs) : data(vs.size() + 1, 0) {
    for (size_t i = 0; i < vs.size(); i++) data[i + 1] = vs[i];
    for (size_t i = 1; i < data.size(); i++) {
      size_t j = i + (i & -i);
      if (j < data.size()) data[j] += data[i];
    }
  }

  void add(int k, const T &x) {
    for (++k; k < (int)data.size(); k += k & -k) data[k] += x;
  }

  T query(int k) const {
    T ret = T();
    for (++k; k > 0; k -= k & -k) ret += data[k];
    return ret;
  }

  int lower_bound(T x) const {
    int i = 0;
    for (int k = 1 << (__lg(data.size() - 1) + 1); k > 0; k >>= 1) {
      if (i + k < data.size() && data[i + k] < x) {
        x -= data[i + k];
        i += k;
      }
    }
    return i;
  }

  int upper_bound(T x) const {
    int i = 0;
    for (int k = 1 << (__lg(data.size() - 1) + 1); k > 0; k >>= 1) {
      if (i + k < data.size() && data[i + k] <= x) {
        x -= data[i + k];
        i += k;
      }
    }
    return i;
  }
};

signed main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> x(n);
  arep(i, x) cin >> i;
  BIT<int> seg(x);
  int ans = 0;
  rep(i, 0, n - 1) ans =
      (ans + ((seg.query(n - 1) - seg.query(i)) % mod1) * x[i]) % mod1;
  cout << ans << '\n';
  return 0;
}