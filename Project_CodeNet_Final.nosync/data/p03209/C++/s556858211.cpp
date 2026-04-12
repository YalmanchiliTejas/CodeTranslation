#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=0; i<n; i++)

vector<ll> a,p;

ll ans(ll n, ll x)
{
  ll y;
  if ( n == 0 ) {
    if ( x <= 0) return 0;
    else return 1;
  } else if ( x <= a[n-1]+1 ) {
    return ans(n-1,x-1);
  } else {
    return p[n-1] + 1 + ans(n-1,x-a[n-1]-2);
  }
  return y;
}

void print_vec(vector<ll> a)
{
  for(auto p:a) cout << p << " ";
  cout << endl;
}

int main()
{
  ll n,x;
  cin >> n >> x;
  a.push_back(1);
  p.push_back(1);
  for (ll i = 0; i <= n-1; i++)
  {
    a.push_back(2*a[i]+3);
    p.push_back(2*p[i]+1);
  }
  /*
  print_vec(a);
  print_vec(p);
  */
  cout << ans(n,x) << endl;

  return 0;
}