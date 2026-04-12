#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
#define div 1000000007
 
int main()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b;
  ll sum = 0;
  
  rep(i,n){
    cin >> a[i];
    sum += a[i];
    if(div <= sum){
      sum = sum % div;
    }
    b.emplace_back(sum);
  }
  ll ans = 0;
  rep(i,n-1){
      ans = (ans + a[n-1-i] * b[n-2-i]) % div;
  }
  cout << ans << endl;
  return 0;
}