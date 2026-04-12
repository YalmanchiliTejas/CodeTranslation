#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > p(8);
int ret = 0,n;
int ch = 0;
int visited[8] = {};

void dfs(int s){
  visited[s]=1;
  ch++;
  if(ch==n){
    ret++;
    visited[s]=0;
    ch--;
    return;
  }
  for(int i=0;i<(int)p[s].size();i++){
    if(visited[p[s][i]]==0)dfs(p[s][i]);
  }
  visited[s]=0;
  ch--;
  return;
}

int main(){
  int m,a,b;
  cin >> n >> m;
  for(int i=0;i<m;i++){
    cin >> a >> b;
    a--; b--;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  dfs(0);
  cout << ret << endl;
  return 0;
}
