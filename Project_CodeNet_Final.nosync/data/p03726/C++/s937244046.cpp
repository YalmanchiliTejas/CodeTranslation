#define _USE_MATH_DEFINES
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>

using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

typedef long long int64;
typedef pair<int, int> ii;
const int INF = 1 << 30;

const int N = 1e5 + 10;
set<int> a[N];
bool visit[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x; --y;
    a[x].insert(y);
    a[y].insert(x);
  }
  set<int> Q;
  for (int i = 0; i < n; ++i) {
    if (a[i].size() == 1) {
      Q.insert(i);
    }
  }
  bool found = false;
  while (!found && !Q.empty()) {
    set<int> nxt;
    for (auto& u : Q) {
      if (a[u].empty()) {
        found = true;
        break;
      }
      int v = *a[u].begin();
      if (Q.find(v) != Q.end()) continue;
      if (nxt.find(v) == nxt.end()) {
        nxt.insert(v);
      } else {
        found = true;
        break;
      }
    }
    // trace(found);
    for (auto& u : nxt) {
      // trace(u);
      visit[u] = true;
    }
    set<int> Q2;
    for (auto& u : nxt) {
      for (auto& v : a[u]) {
        if (Q.find(v) != Q.end() || visit[v]) continue;
        a[v].erase(u);
        if (a[v].size() == 1) {
          Q2.insert(v);
        }
      }
    }
    Q = move(Q2);
    // cout << "Q: " << endl;
    // for (auto& it : Q) {
    //   cout << it << " ";
    // }
    // cout << endl;
  }
  puts(found ? "First" : "Second");
  return 0;
}
