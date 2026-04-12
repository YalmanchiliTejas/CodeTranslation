#include <iostream>
#include <vector>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

using namespace std;

int main() {
  int n;
  vector<int> r;

  while (true) {
    cin >> n;
    if (n == 0) break;
    int sum = 0;
    int max = -1;
    int min = 1001;
    REP(i, n) {
      int val;
      cin >> val;
      if (val > max) max = val;
      if (min > val) min = val;
      sum += val;
    }
    sum = sum - max - min;
    r.push_back((int)(sum / (n - 2)));
  }
  REP(i, r.size()) { cout << r[i] << endl; }
  return 0;
}

