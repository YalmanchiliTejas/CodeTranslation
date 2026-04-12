#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;
#define ll long long int

ll HowMuchMeet ( ll a, ll b, ll k ) {
  ll x = b - k;
  ll y = ( a - k ) / b;
  return x * y + min(x, a - ( y * b + k ) + 1);  
}
int main( ) {
  ll n,k,ans = 0;
  cin >> n >> k;
  if ( k == 0 )
  {
    cout << n * n << endl;
    return 0;
  }
  for ( int b = k + 1; b <= n; b++ ) 
  {
    ans += HowMuchMeet(n,b,k);
  }
  cout << ans << endl;
  return 0;
}

