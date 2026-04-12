#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,n) for(int i = 1; i < n; i++)
#define repll(i,n) for(ll i = 0; i < n; i++)
#define REPll(i,n) for(ll i = 1; i < n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl "\n"
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll a, const ll b){return ((a)+(b)-1)/b;}

int n, m;

int dfs(int now, vii &g, int seen) {
  if(seen == (1<<n)-1) return 1;
  int res = 0;
  for(int x : g[now]) {
    if(seen & (1<<x)) continue;
    res += dfs(x, g, seen|(1<<x));
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  vii g(n);
  rep(i,m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int seen = 1<<0;
  int ans = dfs(0, g, seen);
  cout << ans << endl;
}