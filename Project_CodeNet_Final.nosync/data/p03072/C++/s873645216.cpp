#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <numeric>
#include <climits>
#define ll long long
#define LIM 1000
using namespace std;
int main() {
  vector<int> v;
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  int m = v[0];
  int cnt = 0;
  for (int i = 0; i < v.size(); i++) {
    if (m <= v[i]) {
      cnt++;
    }
    m = max(v[i], m);
  }
  cout << cnt << endl;
  return 0;
}
