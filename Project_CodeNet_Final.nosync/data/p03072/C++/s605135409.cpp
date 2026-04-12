#include <iostream>

using namespace std;

int main(void) {
  int mountains;
  cin >> mountains;

  int heights[mountains];
  for (int i = 0; i < mountains; i ++) {
    cin >> heights[i];
  }

  int viewable = 1;
  int max_height = heights[0];

  for (int i = 1; i < mountains; i++) {
    if (heights[i] >= max_height) {
      viewable++;
      max_height = heights[i];
    }
  }

  cout << viewable << '\n';

  return 0;

}