#include <iostream>
using namespace std;

int main() {
  int Top, South, East, tmp, sum;
  int  n;
  char direction[6];
  while (true) {
    Top = 1;
    South = 2;
    East = 3;
    sum = 1;
    cin >> n;
    if (n==0) {
      break;
    }
    for (int i=0; i<n; i++) {
      cin >> direction;
      switch (direction[0]) {
      case 'N':
        tmp = Top;
        sum += Top = South;
        South = 7-tmp;
        break;
      case 'E':
        tmp = East;
        East = Top;
        sum += Top = 7-tmp;
        break;
      case 'W':
        tmp = Top;
        sum += Top = East;
        East = 7-tmp;
        break;
      case 'S':
        tmp = South;
        South = Top;
        sum += Top = 7-tmp;
        break;
      case 'R':
        tmp = South;
        South = East;
        East = 7-tmp;
        sum += Top;
        break;
      case 'L':
        tmp = East;
        East = South;
        South = 7-tmp;
        sum += Top;
      default:
        break;
      }
    }
    cout << sum << endl;
  }
  return 0;
}