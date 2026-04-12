#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> field(H,vector<char>(W));
  for (int i=0;i<H;i++){
    for (int j=0;j<W;j++){
    cin >> field.at(i).at(j);
  }}
  // なんか判定してくれる処理
  vector<int> ansH(H,-1),ansW(W,-1);
  for (int i=0;i<H;i++){
    bool flag=false;
    for (int j=0;j<W;j++){
      if (field.at(i).at(j)=='#'){
        flag=true;
        break;
      }}
    if (flag){
      ansH.at(i)=i;
    }
  }
  for (int i=0;i<W;i++){
    bool flag=false;
    for (int j=0;j<H;j++){
      if (field.at(j).at(i)=='#'){
        flag=true;
        break;
      }}
    if (flag){
      ansW.at(i)=i;
    }
  }
  int maxW;
  maxW=*max_element(ansW.begin(),ansW.end());
  // がんばって出力
  for (int i:ansH){
    for (int j:ansW){
      if(i!=-1 and j!=-1){
        cout << field.at(i).at(j);
        if(j==maxW){
          cout << endl;
      }}
    }
  }
}