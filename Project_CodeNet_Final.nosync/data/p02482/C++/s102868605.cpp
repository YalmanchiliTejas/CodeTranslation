#include <iostream>
#include <string>

int main() {
  using namespace std;

  int a, b;
  string result;
  
  cin >> a >> b;

  if (a < b) {
    result = "a < b";
  } else if (a > b) {
    result = "a > b";
  } else {
    result = "a == b";
  }

  cout << result << endl;

  return 0;
}