#include <algorithm>
#include <cstring>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;

int main() {
  char s[5];
  cin >> s[0] >> s[1] >> s[2];

  if (s[0] == s[1] && s[1] == s[2]) {
    cout << "No";
  } else {
    cout << "Yes";
  }
  return 0;
}
