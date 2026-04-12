#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
 
 
int main() {
  ll n;
  cin >> n;
  
  ll nsquaresum=0;
  ll nsum=0;
  for(ll i=0; i<n; i++){
    ll a;
    cin >> a;
    nsum += a;
    nsquaresum += a*a;
    nsum %= mod;
    nsquaresum %= mod;
  }
  
  ll result=(nsum*nsum-nsquaresum);
  result = (result+mod)%mod;
  result *= (mod+1)/2;
  result %= mod;
  
  cout << result << endl;
}