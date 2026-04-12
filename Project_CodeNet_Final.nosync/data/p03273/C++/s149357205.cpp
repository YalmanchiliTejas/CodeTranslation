#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int H,W;
  cin >> H >> W;
  vector<vector<char>> M(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> M.at(i).at(j);
    }
  }
  for(int i=0;i<H;i++){
    bool white=true;
    for(int j=0;j<W;j++){
      if(M.at(i).at(j) == '#'){
        white=false;
        break;
      }
    }
    if(white){
      for(int j=0;j<W;j++){
        M.at(i).at(j)='$';
      }
    }
  }
  for(int i=0;i<W;i++){
    bool white=true;
    for(int j=0;j<H;j++){
      if(M.at(j).at(i) == '#'){
        white=false;
        break;
      }
    }
    if(white){
      for(int j=0;j<H;j++){
        M.at(j).at(i)='$';
      }
    }
  }
  for(int i=0;i<H;i++){
    bool printed=false;
    for(int j=0;j<W;j++){
      if(M.at(i).at(j) != '$'){
        cout << M.at(i).at(j);
        printed=true;
      }
    }
    if(printed){
      cout << endl;
    }
  }
}