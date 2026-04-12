#include <iostream>
#include <string>
#include <vector>
#include <set>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int walk(int now, vector<vector<int>> e, std::set<int> remain) {
  remain.erase(now);
  if (remain.size() == 0) return 1;

  int count = 0;

  for (const auto& next : e[now]) {
    if (remain.find(next) != remain.end()) {
      count += walk(next, e, remain);
    }
  }

  return count;
}

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> e(N);
  int a, b;
  rep(i, M) {
    cin >> a >> b;
    a--;
    b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }

  std::set<int> remain;
  for(int i = 1; i < N; i++) {
    remain.insert(i);
  }
  cout << walk(0, e, remain) << endl;

  return 0;
}
