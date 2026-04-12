
#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using gt = greater<int>;
using minq = priority_queue<int, vector<int>, gt>;
using P = pair<ll,ll>;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 


vi to[10];
int ans =0;
int n,m;

bool used[10];
void dfs(int v, int len=1) {
  if (len == n) {
    // TODO:
    ans++;
    return;
  }
  for (int u: to[v]) {
    if (used[u]) continue;
    used[u] = true;
    dfs(u, len+1);
    used[u] = false;
  }
}
int main() {
  cin >> n >> m;
  
  rep(i,m) {
  int a,b; cin >> a >> b; a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  used[0]=true;
  dfs(0);
  cout << ans << endl;
  return 0;
}