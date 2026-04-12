#include <bits/stdc++.h>

#define INF 1 << 29
#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)

using namespace std;

typedef pair<int,int> pii;
typedef long long int ll;

void gen_sosuu(int sosuu[]){
  REP(i,100010){
    sosuu[i] = true;
  }
  sosuu[0] = false;
  sosuu[1] = false;
  sosuu[2] = true;
  FOR(i,2,sqrt(100000)+1){
    if(sosuu[i] == false) continue;
    for(int j = 2; i*j<=100000;j++){
      //printf("%d %d %d\n",i*j,i,j);
      sosuu[i*j] =false;
    }
  }
}

int n,m;
int graph[8][8] = {{0}};
ll sum = 0;
bool visited[8] = {false};
void dfs(int now,bool visited[],int graph[8][8]){
  bool flag = true;
  REP(i,n){
    flag &= visited[i];
  }
  if(flag){
    sum++;
    return;
  }
  REP(i,n){
    if(graph[now][i] == 0) continue;
    if(visited[i]) continue;
    bool tmp = visited[i];
    visited[i] = true;
    graph[now][i]--;
    graph[i][now]--;
    dfs(i,visited,graph);
    visited[i] = tmp;
    graph[now][i]++;
    graph[i][now]++;
  }
  return;
}

int main(){
  scanf("%d %d",&n,&m);
  REP(i,m){
    int a,b;
    scanf("%d %d",&a,&b);
    a--;b--;
    graph[a][b] = 1;
    graph[b][a] = 1;
  }
  visited[0] = true;
  dfs(0,visited,graph);
  printf("%lld\n",sum);
}
