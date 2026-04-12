#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
  ll m = 1000000007;
  ll n, a, ps=0, sm=0;
  cin >> n;
  for(ll i=0;i<n;i++) {
	cin >> a;
    if(i==1)
      ps = (sm*a)%m;
    else
      ps += (sm*a)%m;
    sm = (sm+a)%m;
  }
  cout << ps%m;
  return 0;
}