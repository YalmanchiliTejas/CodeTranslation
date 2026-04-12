#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <cmath>
#include <climits>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())

using namespace std;
typedef long long ll;

int main() {
#ifdef RUN_LOCAL
  ifstream in("../input.txt");
  cin.rdbuf(in.rdbuf());
#endif

  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int a = 0;
  int b = 0;
  for (int i = 0; i < 3; ++i) {
    if (s[i] == 'A') {
      a++;
    }
    else {
      b++;
    }
  }
  if (a != 0 && b != 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  

  return 0;
}