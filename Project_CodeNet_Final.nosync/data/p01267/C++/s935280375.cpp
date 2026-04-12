// 2149_LuckManipulator.cpp
//
#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, x, buf;
deque<int> que;

int dfs(int x, int frame) {
  if(frame > 10000) return -1;

  if(que.front() == x) que.pop_front();

  if(que.empty()) return frame;
  else return dfs((a * x + b) % c, frame + 1);
}

void solve() {
  cout << dfs(x, 0) << endl;
  que.clear();
}

int main() {
  while(cin >> n >> a >> b >> c >> x) {
    if(n == 0 && a == 0 && b == 0 && c == 0 && x == 0) break;
    for(int i = 0; i < n; ++i) {
      cin >> buf;
      que.push_back(buf);
    }
    solve();
  }
  return 0;
}

