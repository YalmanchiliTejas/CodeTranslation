#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
  int x;
  cin >> x;
  if (x == 3 || x == 5 || x == 7)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
