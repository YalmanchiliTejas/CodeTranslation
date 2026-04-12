#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> map(H,vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++)
    {cin >> map.at(i).at(j);}
  }
  vector<int> Wind,Hind;
  for (int i=0;i<H;i++){
    int Wcount=0;
    for (int j=0;j<W;j++){
      if(map.at(i).at(j)=='.')Wcount++;
    }
    if(Wcount==W){
      for (int j=0;j<W;j++){
          map.at(i).at(j)='x';
        }}
  }
  for (int i=0;i<W;i++){
    int Hcount=0;
    for (int j=0;j<H;j++){
      if(map.at(j).at(i)!='#')Hcount++;
    }
    if(Hcount==H){
      for (int j=0;j<H;j++){
          map.at(j).at(i)='x';
        }
      }
  }

  for (int i=0;i<H;i++){
    int xflag=0;
    for (int j=0;j<W;j++){
    if(map.at(i).at(j)!='x'){
    cout<<map.at(i).at(j);
  }else xflag++;
    if(j==W-1){
      if(xflag<W)cout<<endl;
    }


    }
  }

}
