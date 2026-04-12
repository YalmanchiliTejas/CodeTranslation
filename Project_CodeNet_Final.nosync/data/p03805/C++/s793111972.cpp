#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef deque<ll> dqll;

#define MOD 1000000007

int main() {
  ll N, M;

  cin >> N >> M;

  vvll edge(N + 1);
  for (int i = 0; i < M; i++) {
    ll a, b;
    cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  ll ans = 0;
  queue<pair<ll, vector<bool> > > que;
  que.push(make_pair(1, vector<bool>(N + 1, false)));
  while (!que.empty()) {
    auto tmp = que.front();
    que.pop();

    ll v = tmp.first;
    vector<bool> visited = tmp.second;
    visited[v] = true;

    bool comp = true;
    for (int i = 1; i <= N; i++) {
      if (visited[i] == false) {
        comp = false;
        break;
      }
    }  // i
    if (comp) {
      ans++;
      continue;
    }

    for (auto p : edge[v]) {
      if(!visited[p]){
        que.push(make_pair(p, visited));
      }
    } // p
  }

  cout << ans << endl;

  return 0;
}
