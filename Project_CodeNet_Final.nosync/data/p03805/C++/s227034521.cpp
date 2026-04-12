#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}

int ans,N,M;
vector<bool> visited;
vector<vector<bool>> edge;
void dfs(int current_node , vector<bool> visited){
  for(int i = 0; i < N; i++){
    if(visited[i] && i == N-1){
      ans ++;
      return ;
    }else if(visited[i]) continue;
    else break;
  }

  for(int i = 0; i < N; i++){
    if(visited[i]) continue;
    else if(edge[current_node][i] == false) continue;
    else if(edge[current_node][i] && visited[i] == false){
      visited[i] = true;
      dfs(i,visited);
      visited[i] = false;
    }
  }
  return ;
}

int main(){
  int a,b;
  cin >> N >> M;
  edge = vector<vector<bool>>(N,vector<bool>(N,false));
  visited = vector<bool>(N,false);
  for(int i = 0; i < M; i++){
    cin >> a >> b ;
    edge[a-1][b-1] = true;
    edge[b-1][a-1] = true;
  }
  visited[0] = true;
  dfs(0,visited);
  cout << ans << endl;
  return 0;
}
