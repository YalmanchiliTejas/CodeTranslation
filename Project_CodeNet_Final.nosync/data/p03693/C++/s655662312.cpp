#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  int N=100*r+10*g+b; // 3桁の数字Nを求める
  if (N%4==0) cout << "YES";
  else cout << "NO";
}