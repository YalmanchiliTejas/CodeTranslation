#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  bool ans = (g * 10 + b) % 4 == 0;
  cout << (ans ? "YES" : "NO") << endl;
}
