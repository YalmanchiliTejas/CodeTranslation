#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <deque>
#define INF 1e9
#define MOD 1000000007
#define mod(x) ((x % MOD) + MOD) % MOD
#define MAX_N 100001

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int par[MAX_N];
int myrank[MAX_N];

void init(int n)
{
  for (int i = 0; i < n; i++) {
    par[i] = i;
    myrank[i] = 0;
  }
}

int find(int x)
{
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}

void unite(int x, int y)
{
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (myrank[x] < myrank[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if(myrank[x] == myrank[y]) myrank[x]++;
  }
}

bool same(int x, int y)
{
  return find(x) == find(y);
}

int main() {
  int N;
  cin >> N;
  init(N);

  P x[MAX_N];
  P y[MAX_N];
  for (int i = 0; i < N; i++) {
    int x_, y_;
    cin >> x_ >> y_;
    x[i] = make_pair(x_, i);
    y[i] = make_pair(y_, i);
  }
  sort(x, x + N);
  sort(y, y + N);

  pair<int, P> dis[MAX_N * 2];

  for (int i = 0; i < N - 1; i++) {
    dis[i] = make_pair(x[i+1].first - x[i].first, make_pair(x[i+1].second, x[i].second));
  }
  for (int i = 0; i < N - 1; i++) {
    dis[N - 1 + i] = make_pair(y[i+1].first - y[i].first, make_pair(y[i+1].second, y[i].second));
  }

  sort(dis, dis + 2*(N-1));

  int ans = 0;
  for (int i = 0; i < 2*(N-1); i++) {
    int d = dis[i].first, l = dis[i].second.first, r = dis[i].second.second;
    if (!same(l, r)) {
      ans += d;
      unite(l, r);
    }
  }

  cout << ans << endl;

  return 0;
}
