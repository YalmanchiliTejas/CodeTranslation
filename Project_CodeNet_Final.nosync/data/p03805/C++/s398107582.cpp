#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
int N,M; cin >> N >> M;
  vector<vector<bool>> E(N,vector<bool>(N,false));
  for(int i = 0; i < M; i++){
    int u,v; cin >> u >> v; u--; v--;
    E[u][v] = true; E[v][u] = true;}
  
  vector<int> p(N - 1);
  for(int i = 0; i < N - 1; i++){
    p[i] = i + 1;} 
  int cnt = 0;
  do{
    bool flag = true;
  // 0 →　p[0] → ___ → p[N-2] まで全て直接繋がっているかを調べる
  for(int i = 0; i < N - 1; i++){
    if( i == 0){ //この場合は 0 → p[0]を調べる必要がある
      if(E[0][p[0]] == false){ flag = false;}}
    else {
    if( E[p[i-1]][p[i]] == false){ flag = false;}}}
    
   if( flag){ cnt++;}
  } while( next_permutation(p.begin(),p.end()));
    
          cout << cnt << endl; return 0;}