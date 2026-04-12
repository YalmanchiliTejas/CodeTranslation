#include <bits/stdc++.h>
using namespace std;


int main() {
  int N, M; cin >> N >> M;
  int E[8][8];
  for(int i=0; i<8; i++) for(int j=0; j<8; j++) E[i][j]=0;
  int a,b;
  for(int i=0; i<M; i++){
    cin >> a >> b; a--; b--;
    E[a][b]=1; E[b][a]=1;
  }
  
  stack<int> path;
  int reached[8]={}, result=0;
  int search=0;
  
  path.push(0);
  reached[0]=1;
  while(path.empty()==0){
    if(path.size()==N){
      result++;
      search=path.top();
      reached[search]=0;
      path.pop();
    }else{
      bool forward=false;
      if(search!=N-1){
        for(int i=search+1; i<N; i++){
          if(E[path.top()][i]==1&&reached[i]==0){
            path.push(i);
            reached[i]=1;
            search=0;
            forward=true;
            break;
          }
        }
      }
      if(forward==false){
        search=path.top();
        reached[search]=0;
        path.pop();
      }
    }
  }
  cout << result << endl;
}