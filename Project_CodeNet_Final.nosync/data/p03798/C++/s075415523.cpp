#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)(1e5 + 5);

int n, c;
string s;

string ans;

bool decide(char c0, char c1) {
  string cand(n + 2, 'z');

  cand[0] = c0;
  cand[1] = c1;
  for (int i = 2; i < n + 2; ++i) {
    if (cand[i - 1] == 'S') {
      if (s[(i - 1) % n] == 'o') cand[i] = cand[i - 2];
      else cand[i] = cand[i - 2] == 'S' ? 'W' : 'S';
    }
    else {
      if (s[(i - 1) % n] == 'o') cand[i] = cand[i - 2] == 'S' ? 'W' : 'S';
      else cand[i] = cand[i - 2];
    }
  }

  ans = cand;

  return (cand[n] == cand[0] && cand[n + 1] == cand[1]);
}

int main(void) {
  // Here your code !
  scanf("%d", &n);
  cin >> s;

  if (decide('S', 'S')) {
    for (int i = 0; i < n; ++i) {
      printf("%c", ans[i]);
    }
  }
  else if (decide('S', 'W')) {
    for (int i = 0; i < n; ++i) {
      printf("%c", ans[i]);
    }
  }
  else if (decide('W', 'S')) {
    for (int i = 0; i < n; ++i) {
      printf("%c", ans[i]);
    }
  }
  else if (decide('W', 'W')) {
    for (int i = 0; i < n; ++i) {
      printf("%c", ans[i]);
    }
  }
  else {
    printf("-1");
  }

  printf("\n");

  return 0;
}
