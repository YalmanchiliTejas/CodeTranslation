#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> connection(8, vector<bool> (8));

int one_stroke(int tmp_node, int N, vector<bool> visited){
  bool complete = true;
  for (int i=0; i<N; i++){
    if(visited.at(i) == false){
      complete = false;
    }
  }
  if(complete){
    return 1;
  }
  
  int cnt = 0;
  for (int i=0; i<N; i++){
    if(connection.at(tmp_node).at(i)==false){continue;}
    if(visited.at(i)==true){continue;}
    
    visited.at(i) = true;
    cnt += one_stroke(i, N, visited);
    visited.at(i) = false;
  }
  return cnt;
}
    
  


int main(){
  int N, M; cin >> N >> M;
  for (int i=0; i<M; i++){
    int x, y;
    cin >> x >> y;
    connection.at(x-1).at(y-1)=connection.at(y-1).at(x-1)=true;
  }
  
  vector<bool> visited(N, false);
  visited.at(0)=true;
  cout << one_stroke(0, N, visited) << endl;
}