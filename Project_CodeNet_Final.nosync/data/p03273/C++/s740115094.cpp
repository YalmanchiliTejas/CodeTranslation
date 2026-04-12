#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<char>> vec(H, vector<char>(W)); //入力される値

  vector<bool> vecH(H, false); // i行目に＃があるならtrue,ないならfalse
  vector<bool> vecW(W, false); // j列目に＃があるならtrue,ないならfalse


  for(int i=0; i<H; i++) {
      for(int j=0; j<W; j++) {
          cin >> vec.at(i).at(j);

          if(vec.at(i).at(j) == '#') {
              vecH.at(i) = true;
              vecW.at(j) = true;
          }

      }
  }

  for(int i=0; i<H; i++) {
      for(int j=0; j<W; j++) {
          if(vecH.at(i) && vecW.at(j)) {
              cout << vec.at(i).at(j);
          }
      }
      if(vecH.at(i)) cout << endl;
  }
}