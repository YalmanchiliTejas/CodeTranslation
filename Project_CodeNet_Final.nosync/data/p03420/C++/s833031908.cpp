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
  cin >> n >> k;
  
  if(k == 0){
    cout << n * n << endl;
    return 0;
  }

  ll ans = 0;
  for(ll i = 0; i <= n; i++){
    if(i > k){
      ans += n / i * (i - k);
      ans += max(0LL, (n % i) - k + 1);
    }
  }

  cout << ans << endl;

  return 0;
}
