#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;
using ll = long long int;
ll mod = 1e9 + 7;

template <typename number>
pair<number, number> extended_euclid(number a, number b)
{
    number r0, r1, a0, a1, b0, b1;
    r0 = a; r1 = b;
    a0 = 1; a1 = 0;
    b0 = 0; b1 = 1;
    while (r1>0) {
        number q1 = r0 / r1;
        number r2 = r0 % r1;
        number a2 = a0 - q1 * a1;
        number b2 = b0 - q1 * b1;
        r0 = r1 ; r1 = r2;
        a0 = a1 ; a1 = a2;
        b0 = b1 ; b1 = b2;
    }
    number c = r0;
    a = a0; //x
    b = b0; //y
    return  {a, c};
}

//Nを法とした逆元を求める関数
template  <typename number>
number inverse_N(number a, number N)
{
    pair<number, number> result = extended_euclid(a, N);
    if(result.first < 0)
    {
        result.first = result.first + N;
    }
    return result.first;
}

ll calc(ll unit, ll n, ll m)
{
  ll result = 0;
  //m = (m * m) % mod;
  m = (m * m);
  for(ll i = 1; i < n; i++)
  {
    ll temp = (m * (n - i)) % mod;
    ll temp2 = (temp * unit) % mod;
    ll temp3 = (temp2 * i) % mod;
    result = (result + temp3) % mod;
  }
  return result;
}

int main()
{
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> dp(n * m + 1, 0);
  dp[0] = 1;
  for(int i = 1; i <= n * m; i++)
  {
    dp[i] = (dp[i - 1] * i) % mod;
  }
  ll unit = (dp[k - 2] * dp[n * m - k]) % mod;
  unit = inverse_N(unit, mod);
  unit = (dp[n * m - 2] * unit) % mod;
  if(k - 2 == 0)
  {
    unit = 1;
  }
  ll result = 0;
  result = calc(unit, n, m);
  result = (result + calc(unit, m, n)) % mod;
  cout << result << endl;
}
