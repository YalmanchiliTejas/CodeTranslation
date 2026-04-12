#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> table(H,vector<char>(W));
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> table.at(i).at(j);
    }
  }
//1.
  int Hc=0;
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(Hc==0){
        if(table.at(i).at(j)=='#'){
          break;}
        if(j==W-1){
          Hc++;
        }
      }
      else{
        if(table.at(i).at(j)=='#'){
          for(int j=0; j<W; j++){
            table.at(i-Hc).at(j)=table.at(i).at(j);
            table.at(i).at(j)='.';
          }
          break;
        }
        else if(j==W-1){
          Hc++;
        }
      }
    }
  }
  //2.列整理
  int Wc=0;
  for(int i=0; i<W; i++){
    for(int j=0; j<H-Hc; j++){
      if(Wc==0){
        if(table.at(j).at(i)=='#'){
          break;}
        if(j==H-1-Hc){
          Wc++;
        }
      }
      else{
        if(table.at(j).at(i)=='#'){
          for(int j=0; j<H-Hc; j++){
            table.at(j).at(i-Wc)=table.at(j).at(i);
            table.at(j).at(i)='.';
          }
          break;
        }
        else if(j==H-1-Hc){
          Wc++;
        }
      }
    }
  }
//出力
  for(int i=0; i<H-Hc; i++){
    for(int j=0; j<W-Wc; j++){
        cout << table.at(i).at(j);
        if(j==W-1-Wc){
          cout << endl;
        }
    }
  }
}