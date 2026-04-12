#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1000000001;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
  ll n, k;
  cin >> n >> k;

  if(k == 0){
    cout << n*n << endl;
    return 0;
  }

  ll ans = 0;
  for(ll i = k+1; i <= n; ++i){
    ans += (n / i) * (i - k);
    ans += max((ll)0, n % i - k + 1);
  }
  cout << ans << endl;
  return 0;
}
