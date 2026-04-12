
#include "bits/stdc++.h"
using namespace std;

// #define int long long

signed main(void) {
  int num; // num
  num = 0; // count, result
  // num = numeric_limits<int>::min(); // max
  // num = numeric_limits<int>::max(); // min
  int N;
  // int M;
  // array<int, 10000> A;
  // string S;
  // string T;

  int H, W;

  array<array<char, 100>, 100> A;

  cin >> H >> W;
  for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) cin >> A[i][j];

  
  bool changed = true;

  while (changed) {
    changed = false;

    for (int i = 0; i < H; ++i) {
      bool flag = true;
      
      for (int j = 0; j < W; ++j) if (A[i][j] == '#') flag = false;
      
      if (flag) {
        flag = false;
        for (int j = 0; j < W; ++j) if (A[i][j] == '.') flag = true;
      }

      if (flag) {
        for (int j = 0; j < W; ++j) A[i][j] = ' ';
        changed = true;
        break;
      } 
    }

    if (changed) continue;

    for (int j = 0; j < W; ++j) {
      bool flag = true;

      for (int i = 0; i < H; ++i) if (A[i][j] == '#') flag = false;

      if (flag) {
        flag = false;
        for (int i = 0; i < H; ++i) if (A[i][j] == '.') flag = true;
      }

      if (flag) {
        for (int i = 0; i < H; ++i) A[i][j] = ' ';
        changed = true;
        break;
      }
    }

    if (changed) continue;
  }
  
  // while (changed){
  //   changed = false;

  //   if (H <= 1 && W <= 1) break;
    
  //   for (int i = 0; i < H; ++i) {
  //     int flag = true;
  //     for (int j = 0; j < W; ++j) if (A[i][j] != '.') flag = false;
  //     if (flag) {
  //       for (int k = i + 1; k < H; ++k) for (int j = 0; j < W; ++j) A[k - 1][j] = A[k][j];
  //       H = H - 1;
  //       // H = max(H - 1, 1);
  //       changed = true;
  //       break;
  //     }
  //   }
    
  //   if (changed) continue;

  //   for (int j = 0; j < W; ++j) {
  //     int flag = true;
  //     for (int i = 0; i < H; ++i) if (A[i][j] != '.') flag = false;
  //     if (flag) {
  //       // for (int i = 0; i < H; ++i) for (int l = j + 1; l < W; ++l) A[i][l - 1] = A[i][l];
  //       W = W - 1;
  //       // W = max(W - 1, 1);
  //       changed = true;
  //       break;
  //     }
  //   }

  //   if (changed) continue;
  // }

  for (int i = 0; i < H; ++i) {
    int n = 0;
    for (int j = 0; j < W; ++j) {
      if (A[i][j] != ' ') {
        cout << A[i][j];
        ++n;
      }
    }
    if (n > 0) cout << endl;
  }
  
  // cin >> N;
  // for (auto it = A.begin(); it < A.begin() + N; ++it)
  //   cin >> *it;
  // for (auto it = A.begin(); it < A.begin() + N; ++it)
  //   if (*it % 2 == 0) ++num;
  // cout << num << endl;
  
  return 0;
}
