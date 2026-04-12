#include <bits/stdc++.h>
#include <limits>
using namespace std;

int main() {
  int max, min, sum, num, judge;
  while (true) {
    sum = 0;
    min = 1000;
    max = 0;
    cin >> num;
    judge = num;
    if (num == 0) break;
    for (int i = 0; i < judge; i++) {
      cin >> num;
      if (max < num) max = num;
      if (min > num) min = num;
      sum += num;
    }
    int result = (sum - max - min) / (judge - 2);
    cout << result << endl;
  }
  return 0;
}

