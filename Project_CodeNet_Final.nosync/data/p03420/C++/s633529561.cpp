#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

int main()
{
  ll n, k;
  ll ans = 0;

  cin >> n >> k;

  for(ll i = k+1; i <= n; i++){
    ll l = 0, r = 100000, m;
    while(l < r){
      m = (l + r) / 2 + 1;
      if(m * i <= n) l = m;
      else r = m - 1;
    }

    ans += (i - k) * l + max(0LL, n - l * i - k + (k != 0));
  }

  cout << ans << endl;

  return 0;
}
