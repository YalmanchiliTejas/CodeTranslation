#include "bits/stdc++.h"
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<char>> dt((H + 1), vector<char>((W + 1), '0'));

  for(int i = 0; i < H; i++)
  {
    for(int j = 0; j < W; j++)
    {
      cin >> dt.at(i).at(j);
      if (dt.at(i).at(j) == '#') {
        dt.at(i).at(W) = '1';
        dt.at(H).at(j) = '1';
      }
    }
  }

  for(int i = 0; i < H; i++)
  {
    for(int j = 0; j < W; j++)
    {
      if (dt.at(i).at(W) == '0' || dt.at(H).at(j) == '0') {
        continue;
      }else{
        cout << dt.at(i).at(j);
      }
    }
    if (dt.at(i).at(W) == '1') {
      cout << endl;
    }
  }

  return 0;

}
