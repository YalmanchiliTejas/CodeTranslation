#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

const long long MOD = 1000000007;

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll ans=0,t=0,M=7+1e9;
  rep(i,n){
    cin >> a.at(i);
    t += a.at(i);
    t %= M;
  }
  rep(i,n){
    t -= a.at(i);
    t += M;
    t %= M;
    ans += t*a.at(i);
    ans %= M;
  }
  cout << ans << endl;
}
