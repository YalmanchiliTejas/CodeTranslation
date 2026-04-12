#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vi vector<int>
#define vivi vector<vi>
const int INF = 1<<29;
typedef long long ll;

int dp[100][2][100];//dp[keta][未満である][0でない数の個数]

struct UnionFind {
  vi parent;
  UnionFind(int N) : parent(N) {
    rep(i, N)parent[i] = i;
  }

  int getRoot(int child){
    return ((parent[child] == child) ? child : parent[child] = getRoot(parent[child]));
  }
  void unite(int x, int y){
    int root_x = getRoot(x);
    int root_y = getRoot(y);
    if(root_x == root_y)return;
    parent[root_x] = parent[root_y];
  }
  bool isSame(int x, int y){
    return getRoot(x) == getRoot(y);
  }
};
int N, M;
vivi G(10);
bool visited[100];

int dfs(int i){
    int ret = 0;
    bool flg = true;
    rep(i, N)if(!visited[i])flg = false;
    if(flg)return 1;
    for(int v : G[i]){
        if(visited[v])continue;
        visited[v] = true;
        ret += dfs(v);
        visited[v] = false;
    }
    return ret;
}

int main(){
    cin >> N >> M;
    rep(i, M){
        int a, b;cin >> a >> b;
        --a;--b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    visited[0] = true;
    cout << dfs(0);
}
