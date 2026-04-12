#include<bits/stdc++.h>
using namespace std ;
  int N , M ;
  bool board[10][10] ;
 bool visited[10] ;
int dfs(int v , int N , bool visited[10]){
  bool all_visited=true ;
  
  for(int i = 0 ; i < N ; i++){
    if(visited[i]==false)
      all_visited=false ;
  }
  
  if(all_visited){
    return 1 ;
  }
  
  int ret = 0 ;
  for(int i = 0 ; i < N ; i++){
    if(board[v][i]==false) continue ;
    if(visited[i]) continue ;
    
    visited[i] = true ;
    ret+=dfs(i,N,visited);
    visited[i]= false ;
  }
  return ret ;
}

int main () {
  //入力
  cin >> N >> M ;
  
  for(int i = 0 ; i < M ; i++ ){
    int A , B ; 
    cin >> A >> B ;
    board[A-1][B-1] = board[B-1][A-1] = true ;
  }
  
  //演算
  
 
  for(int i = 0 ; i < N ; i++ ){
    visited[i] = false ;
  }
  visited[0] = true ;
  cout << dfs(0,N,visited) << endl ;
  
}