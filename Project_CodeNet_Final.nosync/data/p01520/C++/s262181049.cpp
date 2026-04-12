#include<iostream>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

int main() {
  int n, t, e;
  cin >> n >> t >> e;
  rep (i, n) {
    int x;
    cin >> x;
    for (int j = t - e; j <= t + e; ++j) {
      if (j % x == 0) {
	cout << i + 1 << endl;
	return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}