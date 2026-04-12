#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void){
  int H,W;
  cin >> H >> W;
  
  vector<string>grid(H);
  for(int i=0;i<H;i++){
    cin >> grid[i];
  }
  
  int n;
  for(int i=0;i<H;i++){
    n = 0;
    for(int j=0;j<W;j++){
      if(grid[i][j] == '#')
        n = 1;
    }
    if(n == 0){
      for(int j=0;j<W;j++){
        grid[i][j] = '0';
      }
    }
  }
  
  for(int i=0;i<W;i++){
    n = 0;
    for(int j=0;j<H;j++){
      if(grid[j][i] == '#')
        n = 1;
    }
    if(n == 0){
      for(int j = 0;j<H;j++){
        grid[j][i] = '0';
      }
    }
  }
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(grid[i][j] != '0'){
        cout << grid[i][j];
      }
      
      if(j == W-1)
        cout << endl;
    }
  }
  
  return 0;
}