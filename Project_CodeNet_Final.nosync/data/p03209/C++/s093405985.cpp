#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#define INF 1000000001


using namespace std;

long rec(long n, long x) {
  long length = pow(2, n + 2) - 3;
  if (n == 0 && x == 1) return 1;
  else {
    if (x == 1) {
      return 0;
    } else if (1 < x && x < (length / 2) + 1) {
      return rec(n - 1, x - 1);
    } else if (x == (length / 2) + 1) {
      return rec(n - 1, (length - 3) / 2) + 1;
    } else if ((length / 2) + 1 < x && x < length) {
      return rec(n - 1, (length - 3) / 2) + 1 + rec(n - 1, x - ((length / 2) + 1));
    } else {
      return 2 * rec(n - 1, (length - 3) / 2) + 1;
    }
  }
  cout << n << x << endl;
}

int main() {

  long n, x;
  cin >> n >> x;

  cout << rec(n, x) << endl;
  return 0;

}
