#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int r,g,b;
  cin >> r >> g >> b;
  cout << ((g*10+b)%4==0 ? "YES" : "NO") << endl;
}