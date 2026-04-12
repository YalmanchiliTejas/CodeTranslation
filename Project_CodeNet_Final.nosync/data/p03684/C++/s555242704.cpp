#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <climits>
#include <iomanip>
#include <bitset>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <map>

using namespace std;

struct open {
  int x, y, id;
  open(int x, int y, int id) : x(x), y(y), id(id) {}
};

const int N = 100005;

int p[N];
vector < pair < int, pair <int, int> > > adj;

int fs(int u) {
  return (p[u] == u ? u : p[u] = fs(p[u]));
}

inline bool cmp(const open &a, const open &b) {
  if (a.x != b.x) {
    return a.x < b.x;
  }
  return a.y < b.y;
}

inline bool cmp2(const open &a, const open &b) {
  if (a.y != b.y) {
    return a.y < b.y;
  }
  return a.x < b.x;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < N; i++) p[i] = i;
  vector <open> vec;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    vec.push_back(open(x, y, i));
  }
  sort(vec.begin(), vec.end(), cmp);
  for (int i = 0; i < vec.size(); i++) {
    if (i > 0) {
      int d = min(abs(vec[i].x - vec[i - 1].x), abs(vec[i].y - vec[i - 1].y));
      adj.push_back({d, {vec[i - 1].id, vec[i].id}});
    }
    if (i < n - 1) {
      int d = min(abs(vec[i].x - vec[i + 1].x), abs(vec[i].y - vec[i + 1].y));
      adj.push_back({d, {vec[i + 1].id, vec[i].id}});
    }
  }
  sort(vec.begin(), vec.end(), cmp2);
  for (int i = 0; i < vec.size(); i++) {
    if (i > 0) {
      int d = min(abs(vec[i].x - vec[i - 1].x), abs(vec[i].y - vec[i - 1].y));
      adj.push_back({d, {vec[i - 1].id, vec[i].id}});
    }
    if (i < n - 1) {
      int d = min(abs(vec[i].x - vec[i + 1].x), abs(vec[i].y - vec[i + 1].y));
      adj.push_back({d, {vec[i + 1].id, vec[i].id}});
    }
  }
  sort(adj.begin(), adj.end());
  long long ans = 0;
  for (int i = 0; i < adj.size(); i++) {
    int x = fs(adj[i].second.first);
    int y = fs(adj[i].second.second);
    if (x != y) {
      p[y] = x;
      ans += adj[i].first;
    }
  }
  cout << ans << endl;
  return 0;
}

