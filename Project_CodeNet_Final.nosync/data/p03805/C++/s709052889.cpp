#include<bits/stdc++.h>
using namespace std;

int ans;
int n;

int dfs(vector<int> &visited, vector<pair<int,int>> &v, int x, int num){
  visited[x] = 1;

  num++;
  if(num == n) ans++;
  
  for(auto p: v){
    if(p.first == x && visited[p.second] == 0)
      dfs(visited, v, p.second, num);
  }
  
  num--;
  visited[x] = 0;
}


int main(){
  int m;
  cin >> n >> m;
  
  vector<pair<int,int>> v;
  
  int x,y;
  for(int i=0; i<m; i++){
    cin >> x >> y;
    --x, --y;
    v.push_back(make_pair(x,y));
    v.push_back(make_pair(y,x));
  }
  
  vector<int> visited(n,0);
  
  dfs(visited, v, 0, 0);
  
  cout << ans << endl;
    
}