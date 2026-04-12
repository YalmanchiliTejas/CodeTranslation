#include <iostream>
#include <algorithm>
using namespace std;

int dice[6];

void turn(char c) {
  switch(c) {
    case 'N':
      swap(dice[0], dice[1]);
      swap(dice[1], dice[2]);
      swap(dice[2], dice[3]);
      break;
    case 'S':
      swap(dice[0], dice[3]);
      swap(dice[3], dice[2]);
      swap(dice[2], dice[1]);
      break;
    case 'E':
      swap(dice[0], dice[5]);
      swap(dice[5], dice[2]);
      swap(dice[2], dice[4]);
      break;
    case 'W':
      swap(dice[0], dice[4]);
      swap(dice[4], dice[2]);
      swap(dice[2], dice[5]);
      break;
    case 'R':
      swap(dice[1], dice[4]);
      swap(dice[4], dice[3]);
      swap(dice[3], dice[5]);
      break;
    case 'L':
      swap(dice[1], dice[5]);
      swap(dice[5], dice[3]);
      swap(dice[3], dice[4]);
      break;
    dafault:
      break;
  }
}

int main() {
  int n, s[6] = {1, 2, 6, 5, 3, 4};
  while(cin >> n, n) {
    int ans = 1;
    for(int i = 0; i < 6; i++) dice[i] = s[i];
    for(int i = 0; i < n; i++) {
      string s;
      cin >> s;
      turn(s[0]);
      ans += dice[0];
    }
    cout << ans << endl;
  }
}