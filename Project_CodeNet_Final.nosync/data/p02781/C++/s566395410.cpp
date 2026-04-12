#include <bits/stdc++.h>
using namespace std;

int solve1(const string &n, int index) {
  if (index + 1 > n.size()) return 0;
  if (n.at(index) == '0') return solve1(n, index + 1);
  int d = n.size() - index;
  return n.at(index) - '0' + 9 * (d - 1);
}

int solve2(const string &n, int index) {
  if (index + 2 > n.size()) return 0;
  if (n.at(index) == '0') return solve2(n, index + 1);
  int d = n.size() - index;
  return (n.at(index) - '0' - 1) * 9 * (d - 1) + 81 * (d - 1) * (d - 2) / 2 + solve1(n, index + 1);
}

int solve3(const string &n) {
  if (n.size() < 3) return 0;
  int d = n.size();
  return (n.at(0) - '0' - 1) * 81 * (d - 1) * (d - 2) / 2 + 729 * (d - 1) * (d - 2) * (d - 3) / 6 + solve2(n, 1);
}

int main() {
  string n;
  int k;
  cin >> n >> k;
  if (k == 1) {
    cout << solve1(n, 0) << endl;
  } else if (k == 2) {
    cout << solve2(n, 0) << endl;
  } else {
    cout << solve3(n) << endl;
  }
}
