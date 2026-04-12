#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin >> X;
  
  string result;
  if (X >= 30) {
    result = "Yes";
  } else {
    result = "No";
  }
  
  cout << result << endl;
  
  return 0;
}