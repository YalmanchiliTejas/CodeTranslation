#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  char grid[H][W];
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> grid[i][j];
    }
  }

  bool iex[H];
  bool jex[W];
  fill(iex,iex+H,true);
  fill(jex,jex+W,true);

  for(int i=0;i<H;i++){
    bool isok=true;
    for(int j=0;j<W;j++){
      if(grid[i][j]=='#'){
        isok=false;
        break;
      }
    }
    if(isok) iex[i]=false;
  }
  for(int j=0;j<W;j++){
    bool isok=true;
    for(int i=0;i<H;i++){
      if(grid[i][j]=='#'){
        isok=false;
        break;
      }
    }
    if(isok) jex[j]=false;
  }

  /*for(int i=0;i<H;i++){
    cout << iex[i] << endl;
  }*/

  for(int i=0;i<H;i++){
    if(iex[i]){
      for(int j=0;j<W;j++){
        if(jex[j]) cout << grid[i][j];
      }
      cout << endl;
    }
  }

  return 0;
}