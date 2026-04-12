#include <cstdio>
#include <climits>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <set>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
long long MOD = 1000000007;
long long INF = 1000000000000000; //10^15
typedef long long ll;
typedef unsigned long long ull;

ll powMod(ll x, ll n) {
  if (n == 0) return 1;
  ll r = powMod(x, n / 2);
  if (n % 2 == 0) return (r * r) % MOD;
  return (r * r % MOD) * x % MOD;
}

bool ijv(int i, int j, int h, int w) {
  if (0 <= i && i < h && 0 <= j && j < w) return true;
  return false;
}

char a[2010][2010];
ll s[2010][2010];

int main(void) {

  int n, m;
  cin >> n >> m;
  if (n == m) cout << "Yes" << endl;
  else cout << "No" << endl;
}
