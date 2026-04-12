#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char> > a(H, vector<char>(W, '.'));
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      char temp;
      cin >> temp;
      a[i][j] = temp;
    }
  }  
  int i = 0, j = 0;
  while((i < H) && (j < W)){
    if (((i<(H-1)) && (a[i+1][j] == '#')) && ((j<(W-1)) && (a[i][j+1] == '#'))){
      cout << "Impossible" << endl;
      return 0;
    }else if ((i<(H-1)) && (a[i+1][j] == '#')){
      a[i][j] = '.';
      i++;
    }else if ((j<(W-1)) && (a[i][j+1] == '#')){
      a[i][j] = '.';
      j++;
    }else{
      break;
    }
  }
  a[i][j] = '.';
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      if (a[i][j] == '#'){
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }
  cout << "Possible" << endl;
  return 0;
}
