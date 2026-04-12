#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <climits>
#include <utility>
typedef long long ll;
using namespace std;

int main(int argc, char *argv[]) {
  const ll MOD = 1e9 + 7LL;

  int n, i;
  cin >> n;

  vector<ll> a(n);
  for(i=0;i<n;i++){
    cin >> a[i];
  }

  ll tmp = 0, sum = 0;
  for(i=1;i<n;i++){
    tmp += a[i-1];
    tmp %= MOD;
    sum += (a[i] * tmp) % MOD;
    sum %= MOD;
  }

  if(sum<0LL) sum += MOD;

  cout << sum << endl;

  return 0;
}
