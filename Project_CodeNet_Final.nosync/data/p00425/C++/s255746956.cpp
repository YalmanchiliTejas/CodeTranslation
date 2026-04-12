#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  while (true) {
    int dice[3] = {1, 2, 3};
    int sum = 1, n;
    cin >> n;
    if (n == 0) {
      break;
    }

    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      if (s == "North") {
        int tmp = dice[0];
        dice[0] = dice[1];
        dice[1] = 7 - tmp;
      } else if (s == "East") {
        int tmp = dice[2];
        dice[2] = dice[0];
        dice[0] = 7 - tmp;
      } else if (s == "West") {
        int tmp = dice[0];
        dice[0] = dice[2];
        dice[2] = 7 - tmp;
      } else if (s == "South") {
        int tmp = dice[1];
        dice[1] = dice[0];
        dice[0] = 7 - tmp;
      } else if (s == "Right") {
        int tmp = dice[1];
        dice[1] = dice[2];
        dice[2] = 7 - tmp;
      } else {
        int tmp = dice[2];
        dice[2] = dice[1];
        dice[1] = 7 - tmp;
      }
      sum += dice[0];
    }

    cout << sum << endl;
  }
  return 0;
}