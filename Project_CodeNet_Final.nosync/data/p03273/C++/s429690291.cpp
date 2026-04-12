#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> a(H,vector<char>(W));
  vector<vector<bool>> token(H,vector<bool>(W,0));
  for(int i=0;i<H;i++){//input
    for(int j=0;j<W;j++){
      cin >> a.at(i).at(j);
    }
  }
  for(int i=0;i<H;i++){//行を探索
    int cnt =0;
    for(int j=0;j<W;j++){
      if(a.at(i).at(j)=='.') cnt++;
    }
    if(cnt==W){
      for(int j=0;j<W;j++) token.at(i).at(j) =1;
    }
  }
  
  for(int i=0;i<W;i++){
    int cnt=0;
    for(int j=0;j<H;j++){
      if(a.at(j).at(i)=='.') cnt++;
    }
    if(cnt==H){
      for(int j=0;j<H;j++) token.at(j).at(i) =1;
    }
  }
  
  for(int i=0;i<H;i++){
    int cnt=0;//cnt==W（行全部が空白の時の改行処理のため
    for(int j=0;j<W;j++){
      if(token.at(i).at(j)==1){
        cnt++;
        continue;
      }
      cout << a.at(i).at(j);        
    }
    if(cnt!=W) cout << endl;   	
  }
}


