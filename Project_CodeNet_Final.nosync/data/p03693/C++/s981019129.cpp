#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <set>
#include <map>
#include <complex>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  int ans = (100 * a + 10 * b + c) % 4;
  if (ans == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}