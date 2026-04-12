#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  
  int h = H;
  int w = W;
  
  vector<vector<char>> data(H, vector<char>(W, 0));
  vector<vector<char>> newdata(H, vector<char>(W, 0));
  

  for(int i=0; i<H;i++){
    for(int j=0;j<W;j++){
      char tmp;
      cin >> tmp;
      data.at(i).at(j) = tmp;
    }
  }
  int cnt = -1;
  for(int i=0; i<H;i++){
    int flg = 0;
    for(int j=0;j<W;j++){
      if (data.at(i).at(j) == '#') flg = 1;
    }
    if (flg == 1){
      cnt++;
      for (int j = 0; j<W;j++){
        newdata.at(cnt).at(j) = data.at(i).at(j);
      }
    }
  }
  int newh = cnt+1;
  
  cnt = -1;
  for(int i=0; i<W;i++){
    int flg = 0;
    for(int j=0;j<newh;j++){
      if (newdata.at(j).at(i) == '#') flg = 1;
    }
    if (flg == 1){
      cnt++;
      for (int j = 0; j<newh;j++){
        newdata.at(j).at(cnt) = newdata.at(j).at(i);
      }
    }
  }
  int neww = cnt+1;

  for(int i=0; i<newh;i++){
    for(int j=0;j<neww;j++){
      cout<<newdata.at(i).at(j);
    }
    cout << endl;
  }
  return 0;
}