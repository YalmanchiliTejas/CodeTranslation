#include<iostream>
#include <algorithm>
#include <string>
using namespace std;
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
typedef long long ll;
const int INF = numeric_limits<int>::max();
const int MOD = (1e9 + 7);
bool G[8][8] = {0};

int dfs(int V, int N, bool visited[8]){
  int res = 0;
  visited[V] = true;
  bool ALL = true;
  rep(i, N){
    if(!(visited[i])) ALL = false;
  }
  if(ALL) return 1;
  for(int i=0; i<N; i++){
    if(!G[V][i]) continue;
    else if(visited[i]) continue;
    visited[i] = true;
    res += dfs(i, N, visited);
    visited[i] = false;
  }
  return res;
}
    
 
int main(){
  int N, M;
  cin >> N >> M;
  for(int i=0; i<M; i++){
    int A, B;
    cin >> A >> B;
    G[A-1][B-1] = true;
    G[B-1][A-1] = true;
  }
  bool visited[8] = {0};
  cout << dfs(0, N, visited);
  
 
 }