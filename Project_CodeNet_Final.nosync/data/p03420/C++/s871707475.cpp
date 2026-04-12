#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long int;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}

ll gcd(ll a, ll b) {
  ll tmp;
  if ( b > a) {
    tmp = a;
    a = b;
    b = tmp;
  }
  while (a % b !=0) {
    tmp = b;
    b = a % b;
    a = tmp;
  }
  return b;
}

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

int main(void) {
  ll n, k;
  cin>>n>>k;
  ll kk = (k==0)?1:k;
  ll ans = n*(n-kk+1) - (((n+kk)*(n-kk+1)) / 2);
  ll base = k+1;
  for(ll i=0; i+base<=n; i++) {
    ll init = 2*k+2*i+1;
    ll q = ((n-init)) / (base+i);
    if(init <= n)
      q++;
    ans+=q*(i+1);
    if(0<=(n-(init+(base+i)*q-i)+1))
      ans+=(n-(init+(base+i)*q-i)+1);
  }
  std::cout << ans << std::endl;
  return 0;
}

