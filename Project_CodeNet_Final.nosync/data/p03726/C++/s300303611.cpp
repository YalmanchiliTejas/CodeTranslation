#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef long long int ll;

int N;
set<int> st[100005];
queue<int> que;

int main() {
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    st[a].insert(b);
    st[b].insert(a);
  }

  for (int i = 0; i < N; i++) {
    if (st[i].size() == 1) {
      que.push(i);
    }
  }

  while (!que.empty()) {
    int p = que.front();
    que.pop();

    if (st[p].empty()) {
      cout << "First" << endl;
      return 0;
    }

    int q = *st[p].begin();
    for (auto i : st[q]) {
      st[i].erase(q);
      if (st[i].size() == 1) {
        que.push(i);
      }
    }
  }

  cout << "Second" << endl;

  return 0;
}
