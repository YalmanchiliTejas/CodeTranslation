// https://atcoder.jp/contests/abc055/tasks/abc055_a
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define EACH(i, n) for (auto &i: n)

int main() {
  int n;

  cin >> n;

  int pay = n * 800;
  int back = (n / 15) * 200;

  cout << pay - back << endl;

  return 0;
}
