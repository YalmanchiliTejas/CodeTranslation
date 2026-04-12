#include <bits/stdc++.h>
using namespace std;

int main() {
  int g, b;
  //4の倍数なら、100の位は25*4より無視し、下2桁が4の倍数か見れば良い
  cin >> g >> g >> b;
  //100の位は使わないので変数を削ってメモリを節約する
  if((g * 10 + b) % 4 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
