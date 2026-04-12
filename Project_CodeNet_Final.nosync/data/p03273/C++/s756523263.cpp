#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W;
  cin>>H>>W;
  vector<vector<char>> data(H, vector<char>(W));
  vector<char> kara(W,'x');
 
   for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> data.at(i).at(j);
    }
  }
  for(int i=0;i<H;i++){
    bool A=true;
    for(int j=0;j<W;j++){
      if(data.at(i).at(j)=='#')
        A=false;
    }
    if(A){
      for(int j=0;j<W;j++)
        data.at(i).at(j)='x';
    }
  }
  for(int i=0;i<W;i++){
    bool A=true;
    for(int j=0;j<H;j++){
      if(data.at(j).at(i)=='#')
        A=false;
    }
    if(A){
      for(int j=0;j<H;j++)
        data.at(j).at(i)='x';
    }
  }
  for(int i=0;i<H;i++){
    if(data.at(i)==kara)
      continue;
    for(int j=0;j<W;j++){
      if(data.at(i).at(j)=='x')
        continue;
      cout<<data.at(i).at(j);
    }
    cout<<endl;
  }
}