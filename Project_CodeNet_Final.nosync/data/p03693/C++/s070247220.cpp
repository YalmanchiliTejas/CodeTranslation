#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  cout << ((g*10+b)%4 ? "NO" : "YES") << endl;
  return 0;
}