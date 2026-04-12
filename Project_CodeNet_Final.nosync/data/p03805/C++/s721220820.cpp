#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/integer/common_factor.hpp>
#include <boost/integer/common_factor_rt.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using std::string;
using std::vector;
using std::set;
using std::multiset;
using std::unordered_set;
using std::map;
using std::multimap;
using std::unordered_map;
using std::pair;
using std::cin;
using std::cout;

typedef uintmax_t    ull;
typedef intmax_t     ll;
typedef uint64_t     ul;
typedef uint32_t     ui;
typedef uint8_t      uc;

typedef boost::multiprecision::number<boost::multiprecision::cpp_dec_float<1000>> cpp_dec_float_1000;

constexpr char CRLF  = '\n';
constexpr char SPACE = ' ';
constexpr char VECTOR_COUT_SEPARATOR = SPACE;
constexpr ll INF = 1000'000'007;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> std::ostream& operator<< (std::ostream& os, const std::vector<T>& vc) { for(auto it = vc.begin(); it != vc.end(); ++it) { if (std::next(it) == vc.end()) os << *it; else os << *it << VECTOR_COUT_SEPARATOR; } return os; }
template<class T1, class T2> inline std::ostream & operator<< (std::ostream & os, const std::pair<T1, T2> & p) { return os << p.first << ' ' << p.second; }

using Vector = vector<vector<ui>>;
Vector g_edge;
vector<int> g_memo;
ll g_cnt = 0;

void rec(int cur)
{
  bool emp = true;
  for (int next = 0; next < g_edge[cur].size(); ++next) {
    if (cur == next) {
      continue;
    }
    if (g_edge[cur][next] && !g_memo[next]) {
      emp = false;
      g_memo[next] = 1;
      rec(next);
      g_memo[next] = 0;
    }
  }
  if (emp) {
    if (boost::accumulate(g_memo, 1, [](auto r, auto i) { return i & r; })) {
      ++g_cnt;
    }
  }
  return;
}

void solve(void)
{
  int N, M; cin >> N >> M;
  vector<vector<ui>> way(N, vector<ui>(N));
  for (int i = 0; i < M; ++i) {
    int a, b; cin >> a >> b;
    --a; --b;
    way[a][b] = 1;
    way[b][a] = 1;
  }
  g_edge = std::move(way);
  g_memo.resize(N);

  g_memo[0] = 1;
  rec(0);

  cout << g_cnt << CRLF;
  return;
}

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  solve();

  return 0;
}
