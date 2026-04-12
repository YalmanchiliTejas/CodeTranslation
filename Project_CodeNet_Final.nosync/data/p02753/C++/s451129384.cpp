#include <iostream>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() {
  string s;
  cin >> s;

  string ans = "No";
  for (int i = 0; i < s.length() - 1; i++)  {
    if (s[i] == 'A' && s[i+1] == 'B') ans = "Yes";
    if (s[i] == 'B' && s[i+1] == 'A') ans = "Yes";
  }
  
  cout << ans << endl;
  return 0;
}