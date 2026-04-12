#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int a,b,n,m;
vector< vector<int> > edge;
vector<int> flag;
int ans = 0;

int dfs(int node, int k){
//  cout<< node << " ";
  flag[node] = 1;
  if(k == n){
    ans++;
    flag[node] = 0;
//    cout << endl;
    return 0;
  }
  for(int i = 0; i < edge[node].size() ; i++){
    if(!flag[edge[node][i]]) dfs(edge[node][i],k+1);
  }
  flag[node] = 0;
//  cout << endl;
  return 0;
}

int main(){
  cin >> n >> m;
  edge = vector< vector<int> >(n+1, vector<int>(0,0));
  for(int i = 0 ;  i < m; i++){
    cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  flag = vector<int>(n+1, 0);
  dfs(1,1);
  cout << ans << endl;
}
