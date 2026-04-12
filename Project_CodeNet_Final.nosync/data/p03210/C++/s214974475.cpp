#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;

void solve(int X) {
  if (X == 7 || X == 5 || X == 3) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}

int main() {
  int X;
  cin >> X;
  solve(X);
  return 0;
}