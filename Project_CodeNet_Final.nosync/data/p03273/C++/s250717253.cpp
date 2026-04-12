# include <bits/stdc++.h>
using namespace std;

int main () {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> Grid (H, vector<char>(W));
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> Grid.at(i).at(j);
    }
  }
  vector<bool> High (H,false);
  vector<bool> Width (W,false);
  
  for (int i = 0; i < H; i++) {
    bool flag = true;
    for (int j = 0; j < W; j++) {
      if (Grid.at(i).at(j) == '#'){
        flag = false;
        break;
      }
    }
    if (flag) {
      High.at(i) = true;
    }
  }
  
  for (int i = 0; i < W; i++) {
    bool flag = true;
    for (int j = 0; j < H; j++) {
      if (Grid.at(j).at(i) == '#'){
        flag = false;
        break;
      }
    }
    if (flag) {
      Width.at(i) = true;
    }
  }
  
   for (int i = 0; i < H; i++) {
     if (High.at(i)) {
       continue;
     }
     for (int j = 0; j < W; j++) {
       if (Width.at(j)) {
         continue;
       }
       cout << Grid.at(i).at(j);
     }
     cout << endl;
   }
}
