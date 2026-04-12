#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <utility>
using namespace std;

int main() {
  int H,W;
  cin>>H>>W;
  
  vector<string> a(H);
  for(int i=0;i<H;++i){
    cin>>a[i];
  }
  
  // 黒いマスが含まれる行と列を記録
  vector<bool> row_ok(H,false);
  vector<bool> col_ok(W,false);
  
  for(int i=0;i<H;++i){
    for(int j=0;j<W;++j){
      if(a[i][j]=='#'){
        row_ok[i]=true;
        col_ok[j]=true;
      }
    }
  }
  
  // 黒いマスがある行と列の出力
  for(int i=0;i<H;++i){
    if(row_ok[i]){
      for(int j=0;j<W;++j){
        if(col_ok[j])
          cout<<a[i][j];
      }
      cout<<endl;
    }
  }
  
}