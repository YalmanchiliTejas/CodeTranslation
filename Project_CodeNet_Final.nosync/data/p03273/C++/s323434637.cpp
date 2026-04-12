#include <bits/stdc++.h>
using namespace std;;
int main () {
  int H, W;
  cin >> H >> W;
  vector<vector<int>> data(H, vector<int> (W,3));
  vector<int> hdata(H,0),wdata(W,0);
  for(int i = 0; i < H; i++) {
    char a , b = ' ';
    int count = 0;
    for(int j = 0; j < W; j++) {
      cin >> a;
      if (a == '.') data.at(i).at(j) = 0;
      else data.at(i).at(j) = 1;
      if (a == '.' && a == b) count++;
      b = a;
      if ((count == W - 1 && W != 1) || (a == '.' && W == 1)) hdata.at(i) = 1;
    }
  }
  for(int i = 0; i < W; i++) {
    int a , b = -1;
    int count = 0;
    for(int j = 0; j < H; j++) {
      a = data.at(j).at(i);
      if (a == 0 && a == b) count++;
      b = a;
      if ((count == H - 1 && H != 1) || (a == 0 && H == 1)) wdata.at(i) = 1;
    }
  }
  for(int i = 0; i < H; i++) {
    if (hdata.at(i) == 1) continue;
    for(int j = 0; j < W; j++) {
      if (wdata.at(j) == 1) continue;
      if(data.at(i).at(j) == 0) cout << '.';
      else cout << '#';
    }
    cout << endl;
  }
  return 0;
}
