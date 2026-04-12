#include<iostream>
#include<set>
using namespace std;
int main(){
  int h,w;
  cin >> h >> w;
  set<int> hs,ws;
  bool same;
  char ch;
  char grid[h][w];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> grid[i][j];
    }
  }
  for(int i=0;i<h;i++){
    ch = '.';
    same=true;
    for(int j=0;j<w;j++){
      if(grid[i][j]!=ch){
        same=false;
        break;
      }
    }
    if(same){
      hs.insert(i);
    }
  }
  for(int i=0;i<w;i++){
    ch = '.';
    same=true;
    for(int j=0;j<h;j++){
      if(grid[j][i]!=ch){
        same=false;
        break;
      }
    }
    if(same){
      ws.insert(i);
    }
  }
  bool print;
  for(int i=0;i<h;i++){
    print=false;
    if(hs.find(i)==hs.end()){
      for(int j=0;j<w;j++){
        if(ws.find(j)==ws.end()){
          print=true;
          cout <<grid[i][j];
        }
      }
      if(print){
        cout << endl;
      }
    }
  }
}
