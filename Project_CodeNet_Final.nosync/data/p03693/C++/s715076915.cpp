#include <iostream>
#include <string>

using namespace std;

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  
  int num = 100 * r + 10 * g + b;
  string answer = "NO";
  if (num % 4 == 0) {
    answer = "YES";
  }

  cout << answer << endl;

  return 0;
}