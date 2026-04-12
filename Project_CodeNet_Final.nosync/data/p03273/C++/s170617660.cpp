#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
 
 vector<vector<char>> data(N,vector<char>(M,'.'));
 
 for (int i=0;i<N;i++){
     for (int j=0; j<M;j++){
        cin >> data[i][j];
     }
 }
 
 
  for (int i=0;i<N;i++){
      int x=0;
     for (int j=0; j<M;j++){
        if(data[i][j]=='#') x++;
     }
     if (x==0){
         for (int j=0;j<M;j++){
             data[i][j]='-';
         }
     }
  }
  
  for (int j=0;j<M;j++){
      int x=0;
      for (int i=0;i<N;i++){
          if(data[i][j]=='#') x++;
      }
      if(x==0){
          for(int i=0;i<N;i++){
              data[i][j]='-';
          }
      }
  }
  
  for(int i=0;i<N;i++){
      int x=0;
      for(int j=0;j<M;j++){
          if(data[i][j]!='-') {
              cout << data[i][j];
              x++;
          }
      }
      if(x!=0) cout <<endl;
  }
}
