#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

// Acknowledgement: Special thanks to kyomukyomupurin, who developed this
// template.
template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  int n = 0;
  for (auto e : vec) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& st) {
  int n = 0;
  for (auto e : st) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::map<T, U>& mp) {
  int n = 0;
  for (auto e : mp) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
  for (T& e : vec) is >> e;
  return is;
}

#ifdef LOCAL
#define debug(...) \
  std::cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void debug_out() { std::cerr << '\n'; }

template <class Head, class... Tail>
void debug_out(Head&& head, Tail&&... tail) {
  std::cerr << head;
  if (sizeof...(Tail) != 0) std::cerr << ", ";
  debug_out(std::forward<Tail>(tail)...);
}
using namespace std;
using int64 = long long;

int main() {
  int N, M;
  map<int, vector<int>> mp;
  cin >> N >> M;
  int a, b;
  vector<int> v(N);
  int count = 1;
  for (int& x : v) {
    x = count;
    count++;
  }
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    if (mp.count(a)) {
      mp[a].push_back(b);
    } else {
      mp[a] = {b};
    }
    if (mp.count(b)) {
      mp[b].push_back(a);
    } else {
      mp[b] = {a};
    }
  }
  int path_count = 0;
  bool result;
  do {
    if (v[0] != 1) {
      break;
    }
    for (int i = 0; i < N - 1; i++) {
      vector<int> v_ = mp[v[i]];
      int next_num = v[i + 1];
      result =
          any_of(v_.begin(), v_.end(), [&](int x) { return x == next_num; });
      if (!result) {
        break;
      }
    }
    path_count += result;
  } while (next_permutation(v.begin(), v.end()));
  cout << path_count << endl;
  return 0;
}