#include <iostream>

using namespace std;

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0)
      break;

    int dice[6] = {1, 3, 6, 4, 2, 5};
    int sum = 1;

    for (int i = 0; i < n; ++i) {
      string cmd;
      cin >> cmd;

      int tmp;
      switch (cmd[0]) {
        case 'N':
          tmp = dice[0];
          dice[0] = dice[4];
          dice[4] = dice[2];
          dice[2] = dice[5];
          dice[5] = tmp;
          break;
        case 'E':
          tmp = dice[0];
          dice[0] = dice[3];
          dice[3] = dice[2];
          dice[2] = dice[1];
          dice[1] = tmp;
          break;
        case 'W':
          tmp = dice[0];
          dice[0] = dice[1];
          dice[1] = dice[2];
          dice[2] = dice[3];
          dice[3] = tmp;
          break;
        case 'S':
          tmp = dice[0];
          dice[0] = dice[5];
          dice[5] = dice[2];
          dice[2] = dice[4];
          dice[4] = tmp;
          break;
        case 'R':
          tmp = dice[4];
          dice[4] = dice[1];
          dice[1] = dice[5];
          dice[5] = dice[3];
          dice[3] = tmp;
          break;
        case 'L':
          tmp = dice[4];
          dice[4] = dice[3];
          dice[3] = dice[5];
          dice[5] = dice[1];
          dice[1] = tmp;
          break;
      }

      sum += dice[0];
    }

    cout << sum << endl;
  }
}
