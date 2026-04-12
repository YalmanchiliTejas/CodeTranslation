#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

typedef long long int ll;
typedef vector<ll> V;
typedef vector<V> VV;

int main() {
  // Happy hacking!
  ll n;
  ll h_max = 0;
  ll res = 0;

  cin >> n;
  for(ll i=0; i<n; i++) {
    ll temp;
    cin >> temp;
    if(h_max <= temp) {
      res++;
      h_max = temp;
    }
  }

  cout << res << endl;

  return 0;
}
