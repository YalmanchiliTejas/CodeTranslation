#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;
const int INF = 1001001001;
int n, m;
vector<vector<int>> graph;

int dfs(int v, int s) {
  bool ok = true;
  rep(i, n) {
    int t = s>>i&1;
    if(t == 0) ok = false;
  }
  if(ok) return 1;

  int res = 0;
  for (int u: graph[v]) {
    int nexts = (1<<u)|s;
    if((s>>u&1) == 0) {
      res += dfs(u, nexts);
    }
  }
  return res;
}

int main() {
  cin >> n >> m;
  graph.resize(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  int ans = dfs(0, 1);
  cout << ans << endl;
}
