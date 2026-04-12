#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<map>
#include<numeric>
#include<set>
#include<string>
#include<utility>
#include<vector>
#include<queue>
#include<deque>

#define rep(i, a, n)  for(int i=a; i<n; i++)
#define per(i, a, n)  for(int i=n-1; i>=a; i--)
#define fill0(n)  setfill('0') << right << setw(n)
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MAX 1000001
using namespace std;
typedef long long ll;

int n;
int m;
int a[40];
int b[40];
bool graph[40][40];


int dfs(int x, bool visited[9]){
  bool all_visited=true;
  rep(i,1,n+1){
    if (!visited[i]) all_visited=false;
  }
  if(all_visited)return 1;

  //次の頂点のお話
  int res=0;

  rep(i,1,n+1){
    if(graph[x][i] && !visited[i]){
      visited[i] = true;
      res += dfs(i,visited);
      visited[i] = false;
    }
  }
  return res;
}

int main(){
  std::cin >> n >> m;
  rep(i,1,m+1){
    std::cin >> a[i]>>b[i];
    graph[a[i]][b[i]] = true;
    graph[b[i]][a[i]] = true;
  }
  bool visited[9];
  rep(i,1,n+1){
    visited[i] = false;
  }
  visited[1] = true;
  int ans = dfs(1, visited);
  std::cout << ans << '\n';

}
