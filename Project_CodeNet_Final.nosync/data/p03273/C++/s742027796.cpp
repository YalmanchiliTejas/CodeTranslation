#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> table(h,vector<char>(w));
    for (int i = 0; i < h; i++) 
    {for(int j=0;j<w;j++){
    cin>>table.at(i).at(j);}
  }
   vector<int> allWhiteRows;
  vector<int> allWhiteCols;
  for(int i=0; i<h; i++){
    bool all = true;
    for(int j=0; j<w; j++){
      if(table.at(i).at(j) == '#'){
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
      if(table.at(j).at(i) == '#'){
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
        cout << table.at(i).at(j);
        flag = true;
      }
    }
    if(flag){
      cout << endl;
    }
    
  }
  
}