/**
 *    author  : 𝒌𝒚𝒐𝒎𝒖𝒌𝒚𝒐𝒎𝒖𝒑𝒖𝒓𝒊𝒏
 *    created : 2020-04-01 19:46:57
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

int dp[110][2][5];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s; cin >> s;
  int n = s.size();
  int k; cin >> k;

  dp[0][0][0] = 1;

  for (int i = 0; i < n; ++i) {
    int D = s[i] - '0';
    for (int j = 0; j < 2; ++j) {
      for (int l = 0; l <= 3; ++l) {
        for (int d = 0; d <= (j ? 9 : D); ++d) {
          dp[i + 1][j || (d < D)][l + (d != 0)] += dp[i][j][l];
        }
      } 
    }
  }

  cout << dp[n][0][k] + dp[n][1][k] << endl;

  return 0;
}