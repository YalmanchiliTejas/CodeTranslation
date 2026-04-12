#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }

int ans=0;
int n,m;
int visited_cnt=0;
vector<int> visited;
vector<vector<int>> G;

void dfs(int now){
  visited[now]=1;
  visited_cnt++;
  if(visited_cnt==n) ans++;
  for(int i=0; i<G[now].size(); i++){
    int next=G[now][i];
    if(visited[next]==0) dfs(next);
  }
  visited[now]=0;
  visited_cnt--;
}

int main(int argc, char const *argv[]) {
  cin >> n >> m;
  G=vector<vector<int>>(n);
  visited=vector<int>(n,0);
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--,b--;
    G[a].pb(b),G[b].pb(a);
  }
  dfs(0);
  cout << ans << endl;
  return 0;
}
