#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define reptr(i,n) for(int (i)=(n);(i)>=0;--(i))
#define All(x) (x).begin(),(x).end()
const ll MOD=1e9+7;
const int nmax=8;
using namespace std;
bool graph[nmax+1][nmax+1];

int dfs(int v,int n,bool visited[]){
  //visitedが全てtrueの場合、探索完了
  bool all_visited=true;
  for(int i=1;i<=n;i++){
    if(visited[i]==false){
      all_visited=false;
      break;
    }
  }
  if(all_visited){
    return 1;
  }
  //点vからの総訪問回数sum
  int sum=0;
  for(int i=1;i<=n;i++){
    //直接つながっていないとき
    if(graph[v][i]==false) continue;
    //既に訪れているとき
    if(visited[i]) continue;
    //直接つながっていて、かつまだ訪れていない点のとき
    //点iからNまでの探索回数を足す
    visited[i]=true;
    sum+=dfs(i,n,visited);
    visited[i]=false;
  }
  return sum;
}
int main(){
  int N,M;
  cin >> N >> M;
  bool visited[nmax+1];
  rep(i,M){
    int a,b;
    cin >> a >> b;
    graph[a][b]=graph[b][a]=true;
  }
  for(int i=1;i<=N;i++){
    visited[i]=false;
  }
  //1は既に訪れている
  visited[1]=true;
  cout << dfs(1,N,visited) << endl;
}