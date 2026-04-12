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
/*
1.行整理。
#があったらbreak
・空白行だったら、Hcカウント
・#があったらHc-と交換
2.列整理。*/
  //1.
  int Hc=0;
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(Hc==0){//空白を見つけていない
        if(table.at(i).at(j)=='#'){
          break;}
        if(j==W-1){//すべて'.'を検出
          Hc++;
        }
      }
      else{//Hc>=1 1回でも空白行を検出したあと
        //もし#があれば交換。なければHcをカウント。
        if(table.at(i).at(j)=='#'){
          for(int j=0; j<W; j++){
            table.at(i-Hc).at(j)=table.at(i).at(j);
            table.at(i).at(j)='.';
          }
          break;
        }
        else if(j==W-1){//空白行だった場合
          Hc++;
        }
      }
    }
  }
  //2.列整理、Hc行は検出しなくてOK
  int Wc=0;
  for(int i=0; i<W; i++){//列固定
    for(int j=0; j<H-Hc; j++){//行探索
      if(Wc==0){//空白を見つけていない
        if(table.at(j).at(i)=='#'){
          break;}
        if(j==H-1-Hc){//すべて'.'を検出
          Wc++;
        }
      }
      else{//Wc>=1 1回でも空白行を検出したあと
        //もし#があれば交換。なければHcをカウント。
        if(table.at(j).at(i)=='#'){
          for(int j=0; j<H-Hc; j++){
            table.at(j).at(i-Wc)=table.at(j).at(i);
            table.at(j).at(i)='.';
          }
          break;
        }
        else if(j==H-1-Hc){//空白列だった場合
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