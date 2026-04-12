#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, w;
  cin >> h >> w;
  char grid[110][110];
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      cin >> grid[i][j];
    }
  }
  set<int> num1;
  set<int> num2;
  for(int i=0; i<h; i++){
    int cnt=0;
    for(int j=0; j<w; j++){
      if(grid[i][j] == '.'){
        cnt++;
      }
    }
    if(cnt == w){
      num1.insert(i);
    }
  }
    for(int i=0; i<w; i++){
    int cnt=0;
    for(int j=0; j<h; j++){
      if(grid[j][i] == '.'){
        cnt++;
      }
    }
    if(cnt == h){
      num2.insert(i);
    }
  }
  for(int i=0; i<h; i++){
    if(num1.count(i)){
      continue;
    }
    for(int j=0; j<w; j++){
      if(j != w-1){
        if(num2.count(j)){
          continue;
        }
        cout << grid[i][j];
      }
      else{
        if(num2.count(j)){
          cout << endl;
        }
        else{
          cout << grid[i][j] << endl;
        }
      }
    }
  }
}