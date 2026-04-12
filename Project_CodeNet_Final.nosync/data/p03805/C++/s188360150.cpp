#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<iomanip>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
#define LINF (long long)4e18

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

int N,M;
vector<vector<int>> G;
int ans = 0;

void dfs(int u,vector<int> used){
  used[u] = 1;
  for(auto v:G[u]){
    if(used[v] == -1){
      dfs(v,used);
    }
  }
  bool ok = true;
  rep(i,N){
    if(used[i] == -1) ok = false;
  }
  if(ok) ans++;
}

int main(){
  cin >> N >> M;
  G.resize(N);
  rep(i,M){
    int a,b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> used(N,-1);
  dfs(0,used);
  cout << ans << endl;
  
}
