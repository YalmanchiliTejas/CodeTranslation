#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define Rep(i, n) for(int i=0;i<n;++i)
#define rep(i, n) for(int i=1;i<=n;++i)
#define ll long long int
#define INF 100000000
#define INFLL 100000000000
#define MOD 1000000007
#define PI 3.14159265359
#define All(a) (a).begin(), (a).end()

using namespace std;
using P = pair<ll, ll>;
 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Edge {
  int to;     
  ll weight; 
  Edge(int t, ll w) : to(t), weight(w) { }
};



int N, M;
bool G[10][10];

int main () {
  cin >> N >> M;

  Rep(i, M) {
    int a, b;
    cin >> a >> b;

    G[a][b] = true;
    G[b][a] = true;
  }

  vector<int> v(N);
  iota(All(v), 1);

  int ans = 0;

  do {
    if (v[0] != 1) continue;

    bool flg = true;

    Rep(i, N-1) {
      if (!G[v[i]][v[i+1]]) {
        flg = false;
        break;
      }
    }

    if (flg) ans++;

  } while (next_permutation(All(v)));


  cout << ans << "\n";
}