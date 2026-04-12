#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <numeric>
#include <cmath>
#include <queue>
#include <sstream>
#include <string.h>

using namespace std;
typedef long long ll;

int main()
{
  int n, k;
  string s;
  
  cin >> n >> s >> k;
  k--;

  string res = "";
  for (int i = 0; i < n; i++) {
    if (s[i] != s[k]) {
      res += '*';
    } else {
      res += s[i];
    }
  }
  cout << res << endl;
  return 0;
}
