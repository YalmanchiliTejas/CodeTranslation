#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <sstream>
#include <fstream>
#include <climits>
#include <map>
#include <numeric>
#include <functional>
#include <utility>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main(void) {
  int n;
  cin >> n;
  vector<int> x(n);
  rep(i, n) cin >> x[i];
  vector<int> s;
  s.assign(x.begin(), x.end());
  sort(s.begin(), s.end(), less<int>());

  rep(i, n) {
    int l = s[n / 2 - 1];
    int r = s[n / 2];
    int mid = x[i] <= l ? r : l;
    cout << mid << endl;
  }

  return 0;
}
