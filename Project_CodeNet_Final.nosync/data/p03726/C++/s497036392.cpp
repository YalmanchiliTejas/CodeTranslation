#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void DFS(int v, int from, int curH, const vector<vi>& g, vi& h, vi& p) {
  p[v] = from;
  h[v] = curH;
  for (int to : g[v]) if (to != from) DFS(to, v, curH + 1, g, h, p);
}

void Output(string s) {
  cout << s << endl;
  exit(0);
}

int main()
{
  int n;
  cin >> n;
  vector<vi> g(n);
  vi d(n);

  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
    d[a]++;
    d[b]++;
  }

  vi h(n), p(n);
  DFS(0, -1, 0, g, h, p);

  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; ++i) v[i] = make_pair(h[i], i);
  sort(v.rbegin(), v.rend());

  vector<bool> live(n, true);
  for (auto cur : v) {
    int i = cur.second;
    if (!live[i]) continue;
    live[i] = false;
    if (d[i] == 0) Output("First");
    d[p[i]]--;
    i = p[i];
    if (d[i] == 0) Output("Second");
    if (d[i] != 1) Output("First");
    live[i] = false;
    d[p[i]]--;
  }
  Output("Second");

  return 0;
}
