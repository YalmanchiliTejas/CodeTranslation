#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>>m(h, vector<char>(w));
  vector<vector<char>>copy1(h, vector<char>(w));
  vector<vector<char>>copy2(h, vector<char>(w));
  vector<vector<char>>copy3(h, vector<char>(w));
// mに入力
  for (int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      cin >> m.at(i).at(j);
    }
  }
// 特定の行だけ書き換えてコピー
  for (int i=0; i<h; i++){
    bool a=1;
    for(int j=0; j<w; j++){
     if (m.at(i).at(j)=='#') {
       for(int k=0; k<w; k++){
         copy1.at(i).at(k)=m.at(i).at(k);
       }
       a=0;
       break;
     }
      if(a){
        for(int l=0; l<w; l++){
          copy1.at(i).at(l)='x';
        }
      }
    }
  }
//特定の列だけ
   for (int i=0; i<w; i++){
    bool a=1;
    for(int j=0; j<h; j++){
     if (m.at(j).at(i)=='#') {
       for(int k=0; k<h; k++){
         copy2.at(k).at(i)=m.at(k).at(i);
       }
       a=0;
       break;
     }
      if(a){
        for(int l=0; l<h; l++){
          copy2.at(l).at(i)='x';
        }
      }
    }
  }
//まとめ  
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      if (copy1.at(i).at(j)=='x' || copy2.at(i).at(j)=='x'){
        copy3.at(i).at(j)='x';
      }
      else copy3.at(i).at(j)=m.at(i).at(j);
    }
  }
//出力
for (int i=0; i<h; i++){
  bool b=0;
    for(int j=0; j<w; j++){
      if(copy3.at(i).at(j)!='x'){
       cout << copy3.at(i).at(j);
       b=1;
      }
    }
  if(b)  cout << endl;
  } 

/*  for (int i=0; i<h; i++){
    for(int j=0; j<w; j++){
       cout << copy3.at(i).at(j);
      if (j==w-1) cout << endl;
    }
  }  */
}