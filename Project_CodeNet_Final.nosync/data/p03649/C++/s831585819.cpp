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

int main(void) {

  ll n;
  cin >> n;
  ll a[55], b[55];
  rep(i, n) cin >> a[i];


  sort(a, a + n);
  ll s = 0;
  rep(i, n) {
    b[i] = (a[i] - a[0]) / (n + 1LL);
    s += (a[i] - a[0]) / (n + 1LL);
  }

  rep(i, n) a[i] = a[i] + s - b[i] - n * b[i];
  sort(a, a + n);
  

  ll mi = LLONG_MAX;
  rep(i, n) {
    ll x = max(0LL, a[i] - i);
    mi = min(mi, n - 1 - i + n * x);
  }
  cout << s + mi << endl;
}