#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector< vector<bool> > gragh(8,vector<bool>(8,false));

bool check_reached_all(bool reach[]){
  for(int i=0; i<N; i++){
    if(!reach[i]) return false;
  }
  return true;
}

int dfs(int cur, bool reach[]){
  if(check_reached_all(reach)) return 1;
  
  int ans=0;
  for(int i=1; i<N; i++){
    if(!gragh[cur][i]) continue;
    if(reach[i]) continue;
    reach[i] = true;
    ans += dfs(i,reach);
    reach[i] = false;
  }
  return ans;
}

int main(){
  cin >> N >> M;
  for(int m=0; m<M; m++){
    int i,j;
    cin >> i >> j;
    i--; j--;
    gragh[i][j] = gragh[j][i] = true;
  }
  
  bool reached[N]={false}; 
  reached[0]=true;
  cout << dfs(0,reached) << "\n";
}