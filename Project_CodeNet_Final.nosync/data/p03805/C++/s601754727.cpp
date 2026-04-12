#include <bits/stdc++.h>
#include <boost/range/adaptor/indexed.hpp>
using namespace std;

#define repi(i, a, b) for(int i = (int)(a); i < (int)(b); ++i)
#define rep(i, n) repi(i, 0, n)
#define all(x) (x).begin(), (x).end()

template <typename T>
std::ostream &operator<<(std::ostream &ostr, const std::vector<T> &v) {
  for (const auto &i : v | boost::adaptors::indexed())
    ostr << (i.index() > 0 ? " " : "") << i.value();
  return ostr;
}

int n, m, re = 0;
bool graph[10][10] = {false};
vector<int> che;

inline void input() {
  cin >> n >> m;
  int a, b;
  rep(i, m) {
    cin >> a >> b;
    graph[a][b] = true;
    graph[b][a] = true;
  }
}

inline bool check() {
  int co = 0;
  vector<int> ch = che;
  sort(all(ch));

  rep(i, n) {
    if(ch.at(i) == i+1) {
      co++;
    }
  }

  if(co==n) {
    re++;
  }

  return co==n;
}

inline void dfs(int x, int c) {
  che.push_back(x);

  if(c == n) {
    check();
    che.pop_back();
    return;
  }

  rep(i, 10) {
    if(graph[x][i]) {
      // cout << x << " to " << i << endl;
      dfs(i, c+1);
    }
  }

  che.pop_back();
}

inline void Main() {
  // code
  input();
  dfs(1, 1);
  cout << re << endl;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(20);
  Main();
  return 0;
}
