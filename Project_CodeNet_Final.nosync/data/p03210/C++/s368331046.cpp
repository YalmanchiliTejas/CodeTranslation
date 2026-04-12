#include <iostream>
#include <iomanip> // setprecision
#include <cmath>

using namespace std;
typedef long long ll;
const double long PI = acos(-1);

void solve() {
  ll year;
  cin >> year;
  if (year == 3 || year == 5 || year == 7) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main(void) {
  cout << fixed << setprecision(10);
  solve();
  return 0;
}
