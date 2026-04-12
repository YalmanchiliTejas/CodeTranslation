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
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  
  int base = -1;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (base <= vec[i]) {
      cnt++;
      base = vec[i];
    }
  }
  cout << cnt << endl;
  return 0;
}
