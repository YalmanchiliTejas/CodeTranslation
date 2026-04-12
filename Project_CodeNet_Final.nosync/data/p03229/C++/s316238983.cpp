/**
 *    author  : 𝒌𝒚𝒐𝒎𝒖𝒌𝒚𝒐𝒎𝒖𝒑𝒖𝒓𝒊𝒏
 *    created : 2020-02-16 07:25:51
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

template<class T> using heap = priority_queue<T, vector<T>, greater<T>>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<int64> a(n); cin >> a;

  heap<int64> pq1;
  priority_queue<int64> pq2;

  for (int i = 0; i < n; ++i) {
    pq1.emplace(a[i]);
    pq2.emplace(a[i]);
  }

  deque<int64> dq;

  dq.emplace_back(pq1.top()); pq1.pop();

  while (1) {
    dq.emplace_front(pq2.top()); pq2.pop();
    if ((int)dq.size() == n) break;
    dq.emplace_back(pq2.top()); pq2.pop();
    if ((int)dq.size() == n) break;
    dq.emplace_front(pq1.top()); pq1.pop();
    if ((int)dq.size() == n) break;
    dq.emplace_back(pq1.top()); pq1.pop();
    if ((int)dq.size() == n) break;
  }

  int64 ans1 = 0;
  int64 cur1 = dq.front(); dq.pop_front();

  while (!dq.empty()) {
    int64 nxt = dq.front(); dq.pop_front();
    ans1 += abs(cur1 - nxt);
    cur1 = nxt;
  }

  heap<int64> pq3;
  priority_queue<int64> pq4;

  for (int i = 0; i < n; ++i) {
    pq3.emplace(a[i]);
    pq4.emplace(a[i]);
  }

  deque<int64> dq1;

  dq1.emplace_back(pq4.top()); pq4.pop();

  while (1) {
    dq1.emplace_front(pq3.top()); pq3.pop();
    if ((int)dq1.size() == n) break;
    dq1.emplace_back(pq3.top()); pq3.pop();
    if ((int)dq1.size() == n) break;
    dq1.emplace_front(pq4.top()); pq4.pop();
    if ((int)dq1.size() == n) break;
    dq1.emplace_back(pq4.top()); pq4.pop();
    if ((int)dq1.size() == n) break;
  }

  int64 ans2 = 0;
  int64 cur2 = dq1.front(); dq1.pop_front();

  while (!dq1.empty()) {
    int64 nxt = dq1.front(); dq1.pop_front();
    ans2 += abs(cur2 - nxt);
    cur2 = nxt;
  }

  cout << max(ans1, ans2) << endl;

  return 0;
}