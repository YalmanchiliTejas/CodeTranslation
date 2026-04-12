#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W;
  cin >>H>>W;
  vector<vector<char>> A(H, vector<char>(W));
  vector<int> h;
  vector<int> w;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin>>A[i][j];
    }
  }
  for (int i = 0; i < H; i++) {
   vector<char> v(W,'.');
    if(A[i]!=v){
      h.push_back(i);
    }
  }
  for (int i = 0; i < W; i++) {
    bool a=false;
    for (int j = 0; j < H; j++) {
      if(A[j][i]=='#'){
        a =true;
        break;
      }
    }
    if(a){
      w.push_back(i);
    }
  }
  for (int x : h) {
    for(int y : w){
      cout<<A[x][y];
    }
    cout<<endl;
  }
  return 0;
}