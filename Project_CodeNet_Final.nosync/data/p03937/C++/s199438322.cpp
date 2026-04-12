#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N,M;
  cin>>N>>M;  
  vector<vector<char>> maze(N, vector<char>(M));
  for(int i=0; i<N;i++){
    for(int j=0; j<M;j++){
      cin>>maze[i][j];
    }
  }
  
  int pf=0;
  int ps=0;
    maze[0][0]='.';
    int dx[2]={1,0},dy[2]={0,1};
    while(true){
     if(pf==N-1&&ps==M-1){
       break;
     }
      bool ch=true;
      for(int i=0; i<2;i++){
        int nx=pf+dx[i],ny=ps+dy[i];
        
        if (0<=nx&&nx<N&&0<=ny&&ny<M&&maze[nx][ny]=='#'){
          
          maze[nx][ny]='.';
          pf=nx;
          ps=ny;
          ch=false;
        }
        
      }
      if(ch){
        break;
      }
    
    }
  bool ex=true;
 rep(i,N){
   rep(j,M){
     if(maze[i][j]=='#'){
       ex=false;
     }
   }
 }
  if(ex){
   cout<<"Possible"<<endl;
  }
  else{
    cout<<"Impossible"<<endl;
  }
 
}