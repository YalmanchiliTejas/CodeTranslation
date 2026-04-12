#include <bits/stdc++.h>

//{ START
using namespace std;
#define int int64_t
#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define reps(i, a, n) for (int i = (a); i > (n); --i)
#define arep(i, x) for (auto &&i : (x))
#define irep(i, x) for (auto i = (x).begin(); i != (x).end(); ++i)
//降順はgreater<T>()
#define all(x) (x).begin(), (x).end()
#define rv(s) reverse((s).begin(), (s).end())
// gcd lcmはそのままok
#define gcd(a, b) __gcd(a, b)
#define bits(n) (1 << (n))
#define pcnt(x) __builtin_popcountll(x)
//配列内等要素削除
#define unique(x) (x).erase(unique((x).begin(), (x).end()), (x).end())
#define Fixed(n) fixed << setprecision(n)
//総和
#define sowa(n) ((n) * ((n) + 1)) / 2
#define pb(x, a) (x).push_back(a)
#define fb(x, a) (x).push_front(a)
#define eb(x, a) (x).emplace_back(a)
#define F first
#define S second
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
template <class T>
bool chmax(T &a, const T &b) {  //最大値更新 返り値はbool
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {  //最小値更新 返り値はbool
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
constexpr int INF = 0x3f3f3f3f;
constexpr int LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int mod1 = 1e9 + 7;
constexpr int mod2 = 998244353;
//} END

signed main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, k;
  string s;
  cin >> n >> s >> k;

  char a = s[k - 1];

  rep(i, 0, s.size()) {
    if (s[i] != a) {
      cout << '*';
    } else {
      cout << s[i];
    }
  }
  cout << '\n';
}