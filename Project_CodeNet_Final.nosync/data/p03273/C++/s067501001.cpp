#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<bool>h(H,false);
  vector<bool>w(W,false);
  vector<vector<char>>a(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> a.at(i).at(j);
      if(a.at(i).at(j)=='#'){
        h.at(i)=true;
        w.at(j)=true;
      }
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(h.at(i)==true&&w.at(j)==true){
        cout << a.at(i).at(j);
      }
    }
    if(h.at(i)==true){
      cout << endl;
    }
  }
}