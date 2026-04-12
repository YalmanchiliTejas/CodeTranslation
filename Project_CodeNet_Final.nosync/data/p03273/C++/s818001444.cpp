#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  vector<bool> gyou(H,false),retu(W,false);
  vector<vector<char>> table(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> table.at(i).at(j);
    }
  }

  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(table.at(i).at(j)=='#'){
        gyou.at(i)=true;
        break;
      }
    }
  }

  for(int j=0;j<W;j++){
    for(int i=0;i<H;i++){
      if(table.at(i).at(j)=='#'){
        retu.at(j)=true;
        break;
      }
    }
  }

  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(gyou.at(i)==true){
        if(retu.at(j)==true){
          cout << table.at(i).at(j);
        }
      }
    }
    if(gyou.at(i)==false){
      continue;
    }
    cout << endl;
  }
}