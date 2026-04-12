#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> A(H);
  for (int i = 0; i < H; i++) {
    cin >> A.at(i);
  }
  
  vector<string> B;
  for (int i = 0; i < H; i++) {
    for (int j =0; j < W; j++) {
      if (A.at(i).at(j) == '#') {
        B.push_back(A.at(i));
        break;
      }
    }
  }
  
  vector<string> C(W);
  for (int i = 0; i < B.size(); i++) {
    for (int j = 0; j < W; j++) {
      C.at(j) += B.at(i).at(j);
    }
  }
  
  vector<string> D;
  for (int i = 0; i < W; i++) {
    for (int j =0; j < B.size(); j++) {
      if (C.at(i).at(j) == '#') {
        D.push_back(C.at(i));
        break;
      }
    }
  }
  
  for (int i = 0; i < B.size(); i++) {
    for (int j = 0; j < D.size(); j++) {
      cout << D.at(j).at(i);
    }
    cout << endl;
  }
}
