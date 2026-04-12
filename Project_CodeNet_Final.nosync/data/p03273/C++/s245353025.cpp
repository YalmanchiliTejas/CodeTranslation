#include <bits/stdc++.h>
using namespace std;

int main() {
  int H , W;
  cin >> H >> W;
  vector<vector<char>> data(H,vector<char>(W));
  for (int i=0;i<H;i++){
    for (int j=0;j<W;j++){
      cin >> data.at(i).at(j);
    }
  }
  int count1=0;
  for (int i=0;i<H;i++){
    for (int j=0;j<W;j++){
      if (data.at(i).at(j)=='#'){
        break;
      }
      if (j==W-1){
        for (int k=0;k<W;k++){
          data.at(i).at(k)='&';
        }
      }
    }
  }
  for (int j=0;j<W;j++){
    for (int i=0;i<H;i++){
      if (data.at(i).at(j)=='#'){
        break;
      }
      if (i==H-1){
        for (int k=0;k<H;k++){
          data.at(k).at(j)='&';
        }
      }
    }
  }
  for (int i=0;i<H;i++){
    int sum=0;
    for (int j=0;j<W;j++){
      if (data.at(i).at(j)!='&'){
        cout << data.at(i).at(j);
      }
      else{
        sum++;
      }
      if (sum<W && j==W-1){
        cout << endl;        
      }
    }
  }
}