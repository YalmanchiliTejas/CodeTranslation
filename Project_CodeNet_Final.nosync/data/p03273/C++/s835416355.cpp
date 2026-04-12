
#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> vec(H,vector<char>(W));
  vector<bool> a(H,false);
  vector<bool> b(W,false);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
  	cin >> vec.at(i).at(j);
    if(vec.at(i).at(j)=='#'){
      a[i] = true;
      b[j] = true;
    }
    }
  }
  for(int i=0;i<H;i++){
      if(a[i]){
        for(int j=0;j<W;j++){
        if(b[j])
        cout << vec.at(i).at(j);
        }
        cout << endl;
      }
    }
}