#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
const int SIZE = 8;
vector<vector<int>> T(SIZE);
int dfs(int v,int n,int visited){
   bool flag = true;
   if (visited == (1<<n)-1){
      return 1;
   }
   int ret = 0;
   for (auto &&i : T[v]){
      if (1<<i & visited)continue;
      visited = visited ^ (1<<i);
      ret += dfs(i,n,visited);
      visited = visited ^ (1<<i);
   }
   return ret;
}
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n,m; cin >> n >> m;
   rep(i,m){
      int a, b; cin >> a >> b;
      a--;b--;
      T[a].push_back(b);
      T[b].push_back(a);
   }
   cout << dfs(0,n,1) << endl;
}