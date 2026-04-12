#include<iostream>
#include<algorithm>
using namespace std;

int n, m, cnt = 0;
bool A[10][10] = {};
bool used[10] = {};

void dfs(int u, int d){
  if(d == n){
    cnt++;
    return ;
  }
  
  for(int i = 1;i <= n;i++){
    if(!used[i] && A[u][i]){
      used[i] = true;
      dfs(i, d + 1);
      used[i] = false;
    }
  }
}

int main(){
  int a, b;
  
  cin >> n >> m;
  for(int i = 0;i < m;i++){
    cin >> a >> b;
    A[a][b] = A[b][a] = true;
  }
  
  used[1] = true;
  dfs(1, 1);
  
  cout << cnt << endl;
  
  return 0;
}