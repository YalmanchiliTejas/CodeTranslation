#include <iostream>
using namespace std;

int main() {
  // 入力
  int X;
  cin >> X; // 行列数

  if (X == 3 || X == 5 || X == 7) {
    cout << "YES" <<endl;
  }
  else {
    cout << "NO" << endl;
  }
}
