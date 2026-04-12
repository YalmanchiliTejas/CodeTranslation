#include<bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  string b[100];
  vector<int> row;
  vector<int> col;
  cin >> H >> W;
  for(int i=0; i<H; i++){
    cin >> b[i];
  }
  for(int i=0; i<H; i++){
    bool flag = true;
    for(int j=0; j<W; j++){
      if(b[i][j]=='#'){
        flag = false;
      }
    }
    if(flag) row.push_back(i);
  }
  for(int j=0; j<W; j++){
    bool flag = true;
    for(int i=0; i<H; i++){
      if(b[i][j]=='#'){
        flag = false;
      }
    }
    if(flag) col.push_back(j);
  }
  for(int i=0; i<H; i++){
    if(find(row.begin(), row.end(), i)!=row.end()) continue;
    for(int j=0; j<W; j++){
      if(find(col.begin(), col.end(), j)==col.end()){
        cout << b[i][j];
      }
    }
    cout << endl;
  }
  return 0;
}