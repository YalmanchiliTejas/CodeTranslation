#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<string> masu(H);
  for(int i = 0; i < H; i++){
      cin >> masu.at(i);
  }
   vector<bool> row(H,false);
   vector<bool> col(W,false);
  for(int i = 0; i < H; i++){
   for(int k = 0; k < W; k++){
     if(masu[i][k] == '#'){
       row[i] = true;
       col[k] = true;
     }
  }
  }
  for(int i = 0; i < H; i++)if(row[i]){
    for(int k = 0; k < W; k++)if(col[k]){
      cout << masu[i][k];
    }
   cout << endl;
  }
}