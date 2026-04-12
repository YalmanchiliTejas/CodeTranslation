#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin >> X;
  string answer = "NO";
  if (X == 3 || X == 5 || X == 7) {
    answer = "YES";
  }
  cout << answer << endl;
}