#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  int max = 0;
  int result = 0;
  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    if (max <= h) {
      result++;
      max = h;
    }
  }

  cout << result;
  return 0;
}
