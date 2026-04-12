#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <cmath>

using namespace std;
const long long INF = (long long) (1e18)+1;

int main() {
  // int n;
  // cin >> n;
  string s;
  cin >> s;

  bool flag = false;
  int A = 0;
  int B = 0;

  for (int i=0; i < 3; ++i) {
    if (s[i] == 'A') {
      A++;
    } else {
      B++;
    }
  }

  if (A > 0 && B > 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}