#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin >> h >> w;
  vector<vector<char>> map(h,vector<char>(w));
  
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      cin >> map.at(i).at(j);
    }
  }
  
  vector<int> allWhiteRows;
  vector<int> allWhiteCols;
  for(int i=0; i<h; i++){
    bool all = true;
    for(int j=0; j<w; j++){
      if(map.at(i).at(j) == '#'){
        all = false;
      }
    }
    if(all){
      allWhiteRows.push_back(i);
    }
  }

  for(int i=0; i<w; i++){
    bool all = true;
    for(int j=0; j<h; j++){
      if(map.at(j).at(i) == '#'){
        all = false;
      }
    }
    if(all){
      allWhiteCols.push_back(i);
    }
  }
  
  for(int i=0; i<h; i++){
    bool flag = false;
    for(int j=0; j<w; j++){
      if(
        find(allWhiteRows.begin(), allWhiteRows.end(),i) == allWhiteRows.end()
        && find(allWhiteCols.begin(), allWhiteCols.end(),j) == allWhiteCols.end()
        ) {
        cout << map.at(i).at(j);
        flag = true;
      }
    }
    if(flag){
      cout << endl;
    }
    
  }
  
  
  
}
