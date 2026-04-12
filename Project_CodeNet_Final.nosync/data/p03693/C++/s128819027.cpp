#include <bits/stdc++.h>
using namespace std;

int main() {
  int r,g,b;
  cin >> r >> g >> b;
  string result = "NO";
  if ((g*10+b) % 4 == 0){
    result = "YES";
  }
  cout << result << endl;
}