#include<bits/stdc++.h>
using namespace std;


vector<bool> seen;//訪れたか否か
int count1 = 1;//今まで幾つの頂点に訪れたか

int DFS(vector<vector<int>> &G, int v, int N){  
  
  bool all_seen = true;//全て訪れたかの判定
  for(int i = 0; i < N; i++){
     if(!seen[i]){
       all_seen = false;
     }
  }
  
  

  
  if(all_seen){
    return 1;
    //全て訪れたなら１を返す
  }
  
  int ans = 0;
  //vから行ける場所に行く
  for(int next_v: G[v]){
    if(seen[next_v]) continue;//既に訪れているなら別の頂点へ
    
    seen[next_v] = true;//頂点vは訪れた
    ans += DFS(G, next_v, N);
    seen[next_v] = false;//頂点vに訪れたことをリセット
  }
 
  return ans;
}
 
  

int main(){
  int N, M;
  cin >> N >> M;
  
 //グラフの受け取り
  vector<vector<int>> G(N);
  for(int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    G[a-1].push_back(b-1);
    G[b-1].push_back(a-1);
  }
  
  seen.assign(N, false);
  seen[0] = true;
  cout << DFS(G, 0, N) << endl;
}
  