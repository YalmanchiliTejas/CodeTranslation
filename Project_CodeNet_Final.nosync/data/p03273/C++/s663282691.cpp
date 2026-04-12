# include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  vector<int> h_flg(H);
  vector<int> w_flg(W);
  vector<vector<char>> data(H,vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char tmp;
      cin >> tmp;
      h_flg.at(i) += (tmp=='#');
      w_flg.at(j) += (tmp=='#');
      data.at(i).at(j) = tmp;
    }
  }
  int new_w = 0;
  for (int j = 0; j < W; j++) {
    if (w_flg.at(j) != 0){
      new_w = j;
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (h_flg.at(i) && w_flg.at(j)){
        cout << data.at(i).at(j);
        if (j == new_w){
          cout << endl;
        }
      }
    }
  }
  return 0;
}