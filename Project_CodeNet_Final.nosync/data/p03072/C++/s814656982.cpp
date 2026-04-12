#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<int, int> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}


int main(){

  ll n;
  cin >> n;
  vector<ll> h(n);
  rep(i,n) cin >> h[i];

  ll ans = 0;
  ll max = 0;

  rep(i,n){
    if(h[i]>=max){
      ans++;
      max = h[i];
    }
  }

  cout << ans << endl;

  return 0;
}
