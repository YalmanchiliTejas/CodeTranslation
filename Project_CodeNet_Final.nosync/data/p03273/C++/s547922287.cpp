#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> res(H, vector<char>(W));

  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++) cin >> res.at(i).at(j);
    
  vector<bool> A(H,false),B(W,false) ;

  for (int j = 0; j < W; j++){
    int cnt1 = 0;
    for (int i = 0; i < H; i++){
      if (res.at(i).at(j) == '.') cnt1++;
    }
    if (cnt1 == H) B.at(j) = true;
  }

  for (int i = 0; i < H; i++){
    int cnt2 = 0;
    for (int j = 0; j < W; j++){
      if (res.at(i).at(j) == '.') cnt2++;
    }
    if (cnt2 == W) A.at(i) = true;
  }

//  for (int i=0;i<H;i++) cout << A.at(i);
//  cout << endl;

//  for (int j=0;j<W;j++) cout << B.at(j);
//  cout << endl;
   
  for (int i = 0; i < H; i++){
      if (A.at(i) == true) continue;
    for (int j = 0; j < W; j++){
      if (B.at(j) == true) continue;
      cout << res.at(i).at(j);
    }
    cout << endl;
  }
}

