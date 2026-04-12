#include<bits/stdc++.h>
using namespace std;

int graph[60][60];
bool rireki[15];
int n,m;
int kekka = 0;
int dfs(int cur){
  int ok = 0;
  rireki[cur] = true;
  for(int i = 1;i <= n;i++){
    if(rireki[i] == true){
      ok++;
    }
  }
  if(ok == n){
    kekka++;
  }
  
  for(int i = 1;i <= n;i++){
    if(graph[cur][i] == 1 && rireki[i] == false){
      dfs(i);
      rireki[i] = false;
    }
  }
  return kekka;
}


int main(){
  cin >> n >> m;
  int a[60];
  int b[60];
  for(int i = 1;i <= m;i++){
    cin >> a[i] >> b[i];
    graph[a[i]][b[i]] = graph[b[i]][a[i]] = 1;
  }
          
  cout << dfs(1) << endl;
}