#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> ld;
  ld.push_back(1);
  for (int i = 0; i < n; ++i) {
    int a; cin >> a; a *= -1;
    int j = upper_bound(ld.begin(), ld.end(), a)-ld.begin();
    if (j >= ld.size()) { ld.push_back(a); }
    else { ld[j] = a; }
  }
  cout << ld.size() << endl;
  // for (int d: ld) { cerr << d << endl; }
}

