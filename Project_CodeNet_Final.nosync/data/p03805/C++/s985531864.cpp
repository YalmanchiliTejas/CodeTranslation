#include<iostream>
#include <numeric>
#include <algorithm>
#include<queue>
#include<vector>
using namespace std;
using P = pair<int,int>;
using Graph = vector<vector<bool>>;
int n, m, cnt=0;

int main(){
  cin >> n >> m;
  Graph G(n+1, vector(n+1, false));
  vector<int> Nodes(n+1);
  iota(Nodes.begin(),Nodes.end(), 0);
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    G[a][b] = true;
    G[b][a] = true;
  }
  
  do{
    bool flag = true;
    for(int i=2; i<=n; i++){
      if(G[Nodes[i]][Nodes[i-1]]) continue;
      else{
        flag = false;
        break;
      }
    }
    if(flag) cnt++;
  }while(next_permutation(Nodes.begin()+2, Nodes.end()));
  
  cout << cnt << endl;
}