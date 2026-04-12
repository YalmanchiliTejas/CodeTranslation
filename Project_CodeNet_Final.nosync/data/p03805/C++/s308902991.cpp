#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
ll gcd(ll a, ll b){
  if(b==0) return a;
  else gcd(b,a%b);
}
ll lcm(ll a, ll b){
  return a/gcd(a,b)*b;
}
using Graph = vector<vector<int> >;
Graph G;

void dfs(int v, vector<bool> &seen, int &res) {
    bool end = true;
    for (int i = 0; i < seen.size(); ++i) if (!seen[i] && i != v) end = false;
    if (end) {
        ++res;
        return;
    }

    seen[v] = true;
    for (auto nv : G[v]) {
        if (seen[nv]) continue;
        dfs(nv, seen, res);
    }
    seen[v] = false;
}
int main(){
  int n,m;
  cin >> n >> m;
  G.assign(n,vector<int>());
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
  vector<bool>seen(n,false);
  int ans=0;
  dfs(0,seen,ans);
  cout << ans << endl;
  return 0;
}
