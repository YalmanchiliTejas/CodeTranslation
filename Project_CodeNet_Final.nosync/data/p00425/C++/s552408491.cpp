#include <bits/stdc++.h>
using namespace std;

int n;
int dice[6] = {1, 2, 3, 4, 5, 6};

void N() {
  int s[4] = {0, 1, 5, 4};
  for (int i = 1; i < 4; ++i) {
    swap(dice[s[i]], dice[s[i - 1]]);
  }
}

void E() {
  int s[4] = {0, 3, 5, 2};
  for (int i = 1; i < 4; ++i) {
    swap(dice[s[i]], dice[s[i - 1]]);
  }
}

void R() {
  int s[4] = {1, 2, 4, 3};
  for (int i = 1; i < 4; ++i) {
    swap(dice[s[i]], dice[s[i - 1]]);
  }
}

void S() {
  for (int i = 0; i < 3; ++i) {
    N();
  }
}

void W() {
  for (int i = 0; i < 3; ++i) {
    E();
  }
}

void L() {
  for (int i = 0; i< 3; ++i) {
    R();
  }
}

int main() {
  while (cin >> n, n) {
    for (int i = 0; i < 6; ++i) dice[i] = i + 1;
    int ans = 1;

    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;

      if (s[0] == 'N') N();
      if (s[0] == 'S') S();
      if (s[0] == 'E') E();
      if (s[0] == 'W') W();
      if (s[0] == 'R') R();
      if (s[0] == 'L') L();

      ans += dice[0];
    }

    cout << ans << endl;
  }
}