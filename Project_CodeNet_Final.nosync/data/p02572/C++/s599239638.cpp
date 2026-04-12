#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll n,sum=0;
  cin >> n;
  vector<ll> a(n);
  for(ll i=0;i<n;i++){
    cin >> a.at(i);
    sum += a.at(i);
    sum %= 1000000007;
  }
  
  ll t = 0;
  for(ll i=0;i<n-1;i++){
    sum -= a.at(i);
    if(sum < 0) sum += 1000000007;
    
    t += a.at(i)*sum;
    t %= 1000000007;
  }
  
  cout << t << endl;
  
  return 0;
}
