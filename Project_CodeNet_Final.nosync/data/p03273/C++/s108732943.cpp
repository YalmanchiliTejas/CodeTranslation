#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector <char>> masu(H, vector<char>(W));
  for (int i=0; i<H; i++){
    for (int j=0; j<W; j++){
      cin >> masu.at(i).at(j);
    }
  }
  //for(int i=0; i<H; i++){
  //  for(int j=0; j<W; j++){
  //    cout << masu.at(i).at(j);
  //    if(j == W-1){
  //      cout << endl;
  //    }
  //  }
  //}
  //まず行単位で全部が.を見つける
  vector<int> find_all_white_H(H, 0);
  //for(int i=0; i<H; i++){
  //  cout << find_all_white_H.at(i);
  //}
  for (int i=0; i<H; i++){
    int count = 0;
    for (int j=0; j<W; j++){
      if (masu.at(i).at(j) == '.'){
        count += 1;
      }
    }
    if (count == W){
      find_all_white_H.at(i) = 1;
    }
  }
  //for(int i=0; i<H; i++){
  //  cout << find_all_white_H.at(i);
  //}
  //列単位で全部.を見つける
  int W_sum = 0;
  vector<int> find_all_white_W(W, 0);
  for(int i=0; i<W; i++){
    int count = 0;
    for (int j=0; j<H; j++){
      if (masu.at(j).at(i) == '.'){
        count += 1;
      }
    }
    if (count == H){
      find_all_white_W.at(i) = 1;
      W_sum += 1;
    }
  }
  //出力
  for(int i=0; i<H; i++){
    if(find_all_white_H.at(i) == 1){
      continue;
    }
    for(int j=0; j<W; j++){
      if(find_all_white_W.at(j) == 0){
        cout << masu.at(i).at(j);
      }
      if(j == W-1){
        cout << endl;
      }
    }
  }
}