#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<string> a(H);
  for (int i = 0; i < H; i++) cin >> a.at(i);
  
  int WW = W;
  
  //後ろから全部白の列を削除
  for (int i = W - 1; i >= 0; i--) {
    int white = 1;
    for (int j = 0; j < H; j++)
      if (a.at(j).at(i) == '#')
        white = 0;
    if (white == 1) {
      for (int j = 0; j < H; j++)
        a.at(j).erase(a.at(j).begin() + i);
      WW--;
    }
  }
  
  //出力、ただし全部白の行はとばす
  string whitestr = string(WW, '.');
    
  for (int i = 0; i < H; i++)
    if (a.at(i) != whitestr)
      cout << a.at(i) << endl;
  
}