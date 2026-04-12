#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  vector<vector<char>> field(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> field.at(i).at(j);
    }
  }
  vector<int> tate_i(H),yoko_j(W);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(field.at(i).at(j)=='.'){
        tate_i.at(i)++;
        yoko_j.at(j)++;
      }
    }
  }
  for(int i=0;i<H;i++){
    if(tate_i.at(i)==W){
      continue;
    }
    for(int j=0;j<W;j++){
      if(tate_i.at(i)==W||yoko_j.at(j)==H){
        field.at(i).at(j)='0';
      }
      if(field.at(i).at(j)!='0'){
      	cout << field.at(i).at(j);
      }
    }
    cout << endl;
  }
}
        