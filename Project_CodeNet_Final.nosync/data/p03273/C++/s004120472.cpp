#include <bits/stdc++.h>
using namespace std;

vector<string> input(int H) {
  vector<string> vec(H);
  for(int i = 0; i < vec.size(); i++)
    cin >> vec.at(i);
  return vec;
}

void comp(vector<string> vec, int H, int W) {
  vector<bool> row(H, false);
  vector<bool> col(W, false);
  for(int i = 0; i < row.size(); i++) {
    for(int j = 0; j < col.size(); j++) {
      if(vec.at(i).at(j) == '#') {
        row.at(i) = true;
        col.at(j) = true;
      }
    }
  }
  for(int i = 0; i < row.size(); i++) {
    if(row.at(i)) {
      for(int j = 0; j < col.size(); j++) {
        if(col.at(j))
          cout << vec.at(i).at(j);
      }
      cout << endl;
    }   
  }
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> a = input(H);
  comp(a, H, W);
}