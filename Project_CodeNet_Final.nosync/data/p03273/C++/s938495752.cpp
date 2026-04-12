#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> data(H, vector<char>(W));
  
  for(int i = 0;i<H;i++){
    for(int j= 0;j<W;j++){
      cin >> data.at(i).at(j);
    }
  }

  for(int i = 0;i< H;i++){
    int c =0;
   for(int j = 0;j<W;j++){//各行毎に.の数を計算し、すべて.であれば.をxに変えていく
     if(data.at(i).at(j) == '.') c++;
   }
    if(c==W){
      for(int j =0;j<W;j++){
        data.at(i).at(j) = 'x';
      }
    }
  }
  for(int j = 0;j< W;j++){
    int c =0;
   for(int i = 0;i<H;i++){//各列毎に.の数を計算し、すべて.かxであれば.をxに変えていく
     if(data.at(i).at(j) != '#') c++;
   }
    if(c==H){
      for(int i =0;i<H;i++){
        data.at(i).at(j) = 'x';
      }
    }
  }
  
for(int i = 0;i<H;i++){
    for(int j= 0;j<W;j++){
      if(data.at(i).at(j) != 'x') cout << data.at(i).at(j);
      if(j == W-1) cout << endl;
    }
  }
}