#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<int>> data(H, vector<int>(W));
  
  //Generate table
  for (int i=0; i < H; i++){
    for (int j=0; j < W; j++){
      char x;
      cin >> x;
      if (x == '.'){
        data.at(i).at(j) = 1;
      }
      else if (x == '#'){
        data.at(i).at(j) = 0;
      }
    }
  }
  
  //Find empty row/column (1=empty, 0=occupied)
  vector<int> emp_r(H);
  vector<int> emp_c(W);

  for (int i=0; i < H; i++) emp_r.at(i) = 1;
  for (int j=0; j < W; j++) emp_c.at(j) = 1;
  
  for (int i=0; i < H; i++){
    for (int j=0; j < W; j++){
      emp_r.at(i) *= data.at(i).at(j);
      emp_c.at(j) *= data.at(i).at(j);
    }
  }  

  /*check
  for (int i=0; i < H; i++) cout << emp_r.at(i);
  cout << endl;
  for (int j=0; j < W; j++) cout << emp_c.at(j);
  cout << endl;
  */

  for (int i=0; i < H; i++){
    for (int j=0; j < W; j++){
      bool B = !emp_r.at(i) * !emp_c.at(j);
      if (B) {
        if (data.at(i).at(j)){
          cout << ".";
        }
        else {
          cout << "#";
        }
      }
    }
    if (!emp_r.at(i)) cout << endl;
  }  
  
}
