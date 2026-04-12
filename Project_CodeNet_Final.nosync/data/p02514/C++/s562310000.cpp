#include<iostream>
#include<algorithm>
#include<vector>

#define REP(i,b,n) for(int i=b;i<(int)n;i++)
#define rep(i,n)   REP(i,0,n)
#define FOR(it,o)  for(__typeof((o).begin()) it=(o).begin(); it!=(o).end(); ++it)

using namespace std;
const int INF = 1000000000;
const int N = 100;

class Edge{
public:
  int id, to;
};
int cost[N];
vector<Edge> E[N];
bool cantUse[N], visited[N];
void dfs(int now, int &cnt){
  if(visited[now])return;
  visited[now] = true;
  cnt++;
  FOR(it, E[now]){
    if(cantUse[it->id])continue;
    dfs(it->to, cnt);
  }
}

int main(){
  int n, m;
  while(cin >> n >> m){
    if(n == 0 && m == 0)break;
    rep(i, N)E[i].clear();
    int base = 0;
    rep(i, m){
      Edge e;
      int from;
      cin >> from >> e.to >> cost[i];
      if(cost[i] <= 0){
        base += cost[i];
        continue;
      }
      e.id = i;
      E[from].push_back(e);
      swap(from, e.to);
      E[from].push_back(e);
    }
    int ans = INF;
    {
      int now = 0, cnt = 0;
      rep(k, 100)visited[k] = cantUse[k] = false;
      dfs(now, cnt);
      if(cnt != n){
        ans = 0;
      }
    }
    rep(i, m){
      if(cost[i] <= 0)continue;
      rep(j, m){
        if(cost[j] <= 0)continue;
        rep(k, 100)visited[k] = cantUse[k] = false;
        cantUse[i] = cantUse[j] = true;
        int now = 0, cnt = 0;
        dfs(now, cnt);
        if(cnt != n){
          int tmp = cost[i] + cost[j];
          if(i == j)tmp = cost[i];
          ans = min(ans, tmp);
        }
      }
    }
    cout << ans+base << endl;
  }
  return 0;
}