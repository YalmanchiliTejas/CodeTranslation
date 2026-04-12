#include <bits/stdc++.h>
using namespace std;

int main(){
  int X;
  cin >>X;
  bool suc = 0;
  if (X == 7) suc = 1;
  if (X == 5) suc = 1;
  if (X == 3) suc = 1;
  string ans = (suc) ? "YES" : "NO";
  cout << ans << endl;
}