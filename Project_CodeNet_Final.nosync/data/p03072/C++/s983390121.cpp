#include <bits/stdc++.h>
using namespace std;

int main() {
  int r = 0;
  int m = 0;
  int N;
  cin >> N;

  vector<int> height(N); // N個の山の高さのデータ

  // 標高のデータを受け取る
  for (int i = 0; i < N; i++) {
    cin >> height.at(i);
  }
  // 最大値のチェックと宿数チェック
  for (int i = 0; i < N; i++) {
    if (m <= height.at(i)) {
      m = height.at(i) , r = r+1;
    }
    if (m > height.at(i)){
      m = m , r = r;
    }
  }
   cout << r << endl;
}
