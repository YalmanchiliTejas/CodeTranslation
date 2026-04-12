#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a; i > b; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)

typedef long long ll;


int X, Y, Z;
int ans;

int main() {
  cin >> X >> Y >> Z;

  ans = (X-Z) / (Y+Z);

  cout << ans << endl;
  return 0;
}
