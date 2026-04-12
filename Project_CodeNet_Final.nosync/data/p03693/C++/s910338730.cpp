#include <bits/stdc++.h>
using namespace std;

int main() {
  string r, g, b;
  cin >> r >> g >> b;
  int num = 100*stoi(r)+10*stoi(g)+stoi(b);
  if (num%4==0) cout << "YES" << endl;
  else cout << "NO" << endl;
}