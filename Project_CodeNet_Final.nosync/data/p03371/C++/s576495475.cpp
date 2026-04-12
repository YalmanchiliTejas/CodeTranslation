#include <math.h>
#include <stdio.h>
#include <bitset>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  long long A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  long long total = -1;
  long long sum = 0;
  for (int xy = 0; xy <= 2 * max(X, Y); xy++) {
    sum = 0;
    int x;
    int y;
    if (xy % 2 == 0) {
      x = X - xy / 2;
      y = Y - xy / 2;
    } else {
      x = X - (xy - 1) / 2;
      y = Y - (xy - 1) / 2;
    }
    if (x < 0) {
      x = 0;
    }
    if (y < 0) {
      y = 0;
    }
    sum = A * x + B * y + C * xy;
    if (total < 0) {
      total = sum;
    } else {
      total = min(total, sum);
    }
  }
  cout << total << endl;
}