#include <bits/stdc++.h>
using namespace std;

int main(){
  char grid[100][100],newgrid[100][100],masu[100][100];
  int n,m,c=0,array[100]={},array2[100]={},d=0;
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>grid[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(grid[i][j]=='#'){
        for(int k=0;k<m;k++){
          newgrid[i-c][k]=grid[i][k];
        }
        break;
      }
      c+=(j==m-1);
    }
  }
  for(int i=0;i<m;i++){
    for(int j=0;j<n-c;j++){
      if(newgrid[j][i]=='#'){
        for(int k=0;k<n-c;k++){
          masu[k][i-d]=newgrid[k][i];
      }
        break;
      }
      d+=(j==n-c-1);
    }
  }
  for(int i=0;i<n-c;i++){
    for(int j=0;j<m-d;j++){
      cout<<masu[i][j];
      if(j==m-d-1){
        cout<<endl;
      }
    }
  }
}