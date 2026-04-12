#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <limits>
#include <algorithm>
#include <map>
#include <sstream>

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
static ull tenq = 1000000000;
static ull mod = tenq + 7;

using namespace std;

int main()
{
  ll A, B, AB;
  ll nA, nB;
  cin >> A >> B >> AB >> nA >> nB;
  ll res = 0;
  if (A + B > 2 * AB) {
    ll m = min(nA, nB);
    res = m * 2 * AB;
    nA -= m;
    nB -= m;
  }
  res += min(A, AB * 2) * nA + min(B, AB * 2) * nB;

  cout << res << endl;

  return 0;
}
