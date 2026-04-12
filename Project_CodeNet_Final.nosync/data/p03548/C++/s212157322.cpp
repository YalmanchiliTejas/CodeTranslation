#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  
  int ans = 1;
  int sum = Y+2 * Z;
  while (sum + Y+Z <= X) { 
    sum += Y + Z;
    ans++;
  }
  
  cout << ans << endl;
  
}