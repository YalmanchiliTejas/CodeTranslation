#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <climits>
#include <functional>
#include <queue>
#include <tuple>

#define REP(i,n) for(int i = 0;i < n;i++)

using namespace std;
typedef long long ll;
const int INF = INT_MAX / 4;

const int max_n = 1e3;

// union-find
void init(int n, int par[]) {
  REP(i, n) {
    par[i] = i;
  }
}

int find(int x, int par[]) {
  if (par[x] == x) return x;
  int p = find(par[x], par);
  par[x] = p;
  return p;
}

void unite(int x, int y, int par[]) {
  x = find(x, par);
  y = find(y, par);
  par[x] = y;
}

bool same(int x, int y, int par[]) {
  return find(x, par) == find(y, par);
}


int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  // point, town_id
  priority_queue<pair<int, int>> X, Y;
  // cost, town1, town2
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;

  int x, y;
  REP(i, N) {
    cin >> x >> y;
    X.push(make_pair(x, i));
    Y.push(make_pair(y, i));
  }

  // sort x cost
  pair<int, int> x1, x2;
  x1 = X.top();
  X.pop();
  while( ! X.empty() ) {
    x2 = X.top();
    X.pop();
    q.push(make_tuple(abs(x1.first - x2.first), x1.second, x2.second));
    x1 = x2;
  }
  // sort y
  pair<int, int> y1, y2;
  y1 = Y.top();
  Y.pop();
  while( ! Y.empty() ) {
    y2 = Y.top();
    Y.pop();
    q.push(make_tuple(abs(y1.first - y2.first), y1.second, y2.second));
    y1 = y2;
  }

  ll cost = 0;
  int uftree[N];
  init(N, uftree);
  tuple<int, int, int> t;
  int c, t1, t2;
  while (!q.empty()) {
    t = q.top();
    q.pop();
    c = get<0>(t); t1 = get<1>(t); t2 = get<2>(t);
    // cerr << c << " " << t1 << " " << t2 << "\n";
    if (!same(t1, t2, uftree)) {
      unite(t1, t2, uftree);
      cost += c;
    }
  }

  cout << cost << "\n";
  return 0;
}
