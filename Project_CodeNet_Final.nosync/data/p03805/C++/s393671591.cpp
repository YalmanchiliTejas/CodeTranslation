#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int N,M;
vector<int> G[8];
bool used[8];
int cnt = 0;

void dfs(int v){
  bool allused = true;
  for(int i=0;i<N;i++){
    if(used[i] == false) allused = false;
  }
  if(allused){
    cnt++;
    return;
  }

  //--------------------------
  for(int i=0;i<(int)G[v].size();i++){
    if(!used[G[v][i]]){
      used[G[v][i]] = true;
      dfs(G[v][i]);
      used[G[v][i]] = false;
    }
  }

  return;
}

int main(){
  cin >> N >> M;
  for(int i=0;i<M;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  fill(used,used+8,false);
  used[0] = true;
  dfs(0);

  cout << cnt << endl;
  return 0;
}