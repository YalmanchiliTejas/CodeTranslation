#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007

int N;
vector<int> G[100000];
bool X[100000];
bool damn[100000];

int count(int x) {
  if (damn[x])return 0;
  int c = 0;
  for (int t : G[x]) {
    if (X[t])continue;
    if (damn[t]) return 0;
    c++;
  }
  return c;
}
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N;
  rep(i, N-1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].pb(b);
    G[b].pb(a);
  }
  rep(_, 100) {
    vector<int> xs;
    rep(x, N) {
      if (damn[x]) continue;
      int c = 0;
      for (int t : G[x]) {
        if (damn[t]) {
          c = 0;
          break;
        }
        c += count(t) == 1;
      }
      if (c > 1) {
        cout << "First\n";
        return 0;
      }
      if (c == 1) {
        xs.pb(x);
        for (int t : G[x]) {
          if (damn[t]) continue;
          if (count(t) == 1) {
            damn[t] = true;
          }
        }
      }
    }
    for (int x :xs) X[x] = true;
    rep(x, N) {
      bool f = !damn[x];
      for (int t : G[x]) {
        if (!X[t] || damn[t]) f = false;
      }
      if (f) {
        cout << "First\n";
        return 0;
      }
    }
  }
  cout << "Second\n";
  return 0;
}
