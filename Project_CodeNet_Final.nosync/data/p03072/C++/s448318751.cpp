#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  int max_height = 0;
  int result = 0;

  cin >> n;

  int mountains[n];
  for (int i = 0; i < n; i++) {
    cin >> mountains[i];
  }

  for (int i = 0; i < n; i++) {
    int height = mountains[i];
    if (height >= max_height) {
      result++;
      max_height = height;
    }
  }

  cout << result << endl;

  return 0;
}