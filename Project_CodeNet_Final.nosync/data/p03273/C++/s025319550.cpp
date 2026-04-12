#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;

  vector<char> row(H),col(W);
  vector<vector<char>> mae(H, vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> mae.at(i).at(j);
      if(mae.at(i).at(j)=='#') {
        row.at(i)=1;
      }
    }
  }    

  for(int i=0;i<W;i++){
    for(int j=0;j<H;j++){
      if(mae.at(j).at(i)=='#') {
        col.at(i)=1;
      }
    }
  }  
 
  bool flag;
  
  for(int i=0;i<H;i++){
    flag=false;
    for(int j=0;j<W;j++){   
      if(row.at(i)==1&&col.at(j)==1) {
        flag=true;
        cout << mae.at(i).at(j);
      }
    }
    if(flag)cout<<endl;
  } 
}