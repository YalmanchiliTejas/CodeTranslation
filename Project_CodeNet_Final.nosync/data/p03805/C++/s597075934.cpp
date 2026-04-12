/**
 *    author  : 𝒌𝒚𝒐𝒎𝒖𝒌𝒚𝒐𝒎𝒖𝒑𝒖𝒓𝒊𝒏
 *    created : 2020-03-26 15:24:07
**/

#include <iostream>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>
#include <numeric>
#include <bitset>
#include <cassert>
#include <cctype>
#include <iomanip>
#include <random>
#include <utility>
#include <chrono>

using namespace std;

using int64 = long long;

template<class T> using binary_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template<class T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) { os << '{'; size_t n = vec.size(); for (size_t i = 0; i < n; ++i) { os << vec[i]; if (i != n - 1) os << ','; } os << '}'; return os; }
template<class T, class U> std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) { return os << '{' << p.first << " " << p.second << '}'; }
template<class T, class U> std::ostream& operator<<(std::ostream& os, const std::map<T, U>& mp) { os << '{'; for (auto it = mp.begin(); it != mp.end(); ++it) { os << '{' << it->first << ':' << it->second << '}'; if (it != --mp.end()) os << ','; } os << '}'; return os; }
template<class T> std::ostream& operator<<(std::ostream& os, const std::set<T>& st) { os << '{'; for (auto it = st.begin(); it != st.end(); ++it) { os << *it; if (it != --st.end()) os << ','; } os << '}'; return os; }
template<class T> std::istream& operator>>(std::istream& is, std::vector<T>& vec) { size_t n = vec.size(); for (size_t i = 0; i < n; ++i) is >> vec[i]; return is; }

#define all(_) begin(_), end(_)
#define rall(_) rbegin(_), rend(_)

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...) 1728
#endif

void debug_out() { std::cerr << '\n'; }

template <class Head, class... Tail>
void debug_out(Head&& head, Tail&&... tail) {
  std::cerr << head;
  if (sizeof...(Tail) != 0) std::cerr << ", ";
  debug_out(std::forward<Tail>(tail)...);
}

using graph = std::vector<std::vector<int>>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m; cin >> n >> m;
  graph g(n);
  for (int i = 0; i < m; ++i) {
    int a, b; cin >> a >> b;
    --a; --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }

  vector<int> order(n);
  iota(all(order), 0);

  int ans = 0;

  vector<int> visited(n, 0);

  do {
    if (order[0] != 0) break;
    visited.assign(n, 0);
    int cur = 0;
    bool flag = true;

    for (int i = 1; i < n; ++i) {
      if (find(all(g[cur]), order[i]) == g[cur].end()) {
        flag = false;
      } else {
        cur = order[i];
      }
    }
    if (flag) ++ans;
  } while (next_permutation(all(order)));

  cout << ans << endl;

  return 0;
}