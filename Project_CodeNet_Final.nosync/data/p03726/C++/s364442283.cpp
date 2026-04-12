#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  bool flag = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') {
      flag = 1;
    }
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  if (flag) {
    x = -x;
  }
}
const int N = 200005;
int n, sz[N];
vector<int> g[N];
void dfs(int u, int fa) {
  sz[u] = 1;
  int cnt = 0;
  for (auto v : g[u]) {
    if (v ^ fa) {
      dfs(v, u);
      sz[u] += sz[v];
      cnt += sz[v] & 1;
    }
  }
  if (cnt > 1) {
    puts("First");
    exit(0);
  }
}
int main() {
  read(n);
  if (n & 1) {
    puts("First");
    return 0;
  } 
  for (int i = 1; i < n; ++i) {
    int u, v;
    read(u), read(v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  puts("Second");
  return 0;
}