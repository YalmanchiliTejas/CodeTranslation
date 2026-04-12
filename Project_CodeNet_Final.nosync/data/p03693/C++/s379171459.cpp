#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;

int main() {
  
  int r, g, b;
  cin >> r >> g >> b;
  
  int a = r*100 + g*10 + b;
  
  cout << ((a % 4 == 0) ? "YES" : "NO") << endl;

}