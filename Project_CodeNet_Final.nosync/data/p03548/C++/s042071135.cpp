#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <set>
#include <map>
#include <unordered_map>
#include <complex>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;

int main()
{
  int x, y, z;
  cin >> x >> y >> z;
  int person = y + z, chair = x - z, ans = 0;
  while (chair >= 0) {
    ans++;
    chair -= person;
  }
  cout << ans - 1 << endl;
}
