#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const ll INF = 1LL<<29;
const ll mod = 1e9+7;

#define rep(i, a, b) for(ll (i) = (a); (i) < (b);++i)

ll gcd(ll x, ll y)
{
  if (x % y == 0)
  {
    return y;
  }
  return gcd(y, x % y);
}

int main()
{
  char c;
  cin >> c;
  if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'){
    cout << "vowel" <<endl;
  }else{
    cout << "consonant" <<endl;
  }
  
  return 0;
}