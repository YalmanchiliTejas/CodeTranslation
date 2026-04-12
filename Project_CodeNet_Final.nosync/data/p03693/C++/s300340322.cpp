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
  char a[3];
  cin >> a[0] >> a[1] >> a[2];
  if ((int(a[0]) * 100 + int(a[1]) * 10 + int(a[2])) % 4 == 0){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}
