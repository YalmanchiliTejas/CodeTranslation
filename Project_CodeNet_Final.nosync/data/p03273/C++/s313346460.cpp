#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> A(H, vector<char>(W));
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> A.at(i).at(j);
    }
  }
  vector<int> row(H);
  vector<int> column(W);
  for(int i = 0; i < H; i++){
    int count = 0;
    for(int j = 0; j < W; j++){
      if(A.at(i).at(j) == '#') count++;
    }
    if(count == 0) row.at(i) = 1;
  }
  
  for(int i = 0; i < W; i++){
    int count = 0;
    for(int j = 0; j < H; j++){
      if(A.at(j).at(i) == '#') count++;
    }
    if(count == 0) column.at(i) = 1;
  }
  
  for(int i = 0; i < H; i++){
    if(row.at(i) == 1) continue;
    for(int j = 0; j < W; j++){
      if(column.at(j) == 1) continue;
      cout << A.at(i).at(j);
    }
    cout << endl;
  }
}
