#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
  int it = 0;
  int n;
  string str; int a, b, c;
  while (cin >> n) {
    if (n == 0) break;
    if (it++ != 0) cout << endl;
    vector< pair<pair<int, int>, string> > data(n);
    for (int i = 0; i < n; ++i) {
      cin >> str >> a >> b >> c;
      int val = a*3 + c;
      data[i] = make_pair(make_pair(val, n-i), str);
    }
    sort(data.begin(), data.end());
    for (int i = n-1; i >= 0; --i) {
      cout << data[i].second << "," << data[i].first.first << endl;
    }
  }
}
