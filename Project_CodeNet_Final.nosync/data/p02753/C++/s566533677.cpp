#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <climits>
#include <iomanip>
#include <bitset>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <map>

using namespace std;

int main() {
  string a;
  cin >> a;
  bool ok = 0;
  for (int i = 0; i + 1 < a.size(); i++) {
    if (a[i] == 'A' && a[i + 1] == 'B') {
      ok = 1;
    }
    if (a[i] == 'B' && a[i + 1] == 'A') {
      ok = 1;
    }
  }
  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
