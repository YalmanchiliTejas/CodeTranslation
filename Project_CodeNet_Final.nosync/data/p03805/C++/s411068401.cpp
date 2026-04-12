#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using vll = vector<ll>;

void solve();

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  solve();

  return 0;
}

#define ini(...)   \
  int __VA_ARGS__; \
  in(__VA_ARGS__)

#define inl(...)  \
  ll __VA_ARGS__; \
  in(__VA_ARGS__)

#define ins(...)      \
  string __VA_ARGS__; \
  in(__VA_ARGS__);

void in() {}
template <typename T, class... U>
void in(T& t, U&... u) {
  cin >> t;
  in(u...);
}

void out() {
  cout << endl;
}
template <typename T, class... U>
void out(const T& t, const U&... u) {
  cout << t;
  if (sizeof...(u))
    cout << " ";
  out(u...);
}

#define rep(i, n) for (long long i = 0; i < n; i++)

void solve();
#ifndef ONLINE_JUDGE
#include "./lib.hpp"
#endif

ll dfs(vector<vector<int>> path, vector<bool> visited, int at, int visit_num) {

    if (visited[at])
        return 0;
    if (visit_num == visited.size())
        return 1;

    visited[at] = true;

    ll ret = 0;
    for (auto next : path[at])
        ret += dfs(path, visited, next, visit_num + 1);

    visited[at] = false;
    return ret;
}

void solve() {
    ini(N, M);
    vector<vector<int>> path(N);
    rep(i, M) {
        ini(a, b);
        a--, b--;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    vector<bool> visited(N, false);
    out(dfs(path, visited, 0, 1)); 
}
