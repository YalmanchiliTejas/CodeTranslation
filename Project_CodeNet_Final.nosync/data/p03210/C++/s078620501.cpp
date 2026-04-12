#include <bits/stdc++.h>
using namespace std;

int main() {
  long long X;
  cin >> X;
  
  string result = "NO";
  if (X == 3 || X == 5 || X == 7) {
    result = "YES";
  }
  
  cout << result << endl;
  
  return 0;
}