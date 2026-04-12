#include <bits/stdc++.h>
using namespace std;

int main() {
  // 入力を受け取る
  int r, g, b;
  cin >> r >> g >> b;

  // 計算
  int num = r * 100 + g * 10 + b;
  
  // 出力
  if ((num % 4) == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}