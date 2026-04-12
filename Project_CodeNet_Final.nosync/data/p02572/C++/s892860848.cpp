#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n); i >= 0; i--)
#define loop(i, r, n) for (int i = (r); i < (n); i++)
#define pb push_back
#define all(in) in.begin(),in.end()

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using ll = long long;
using ull = unsigned long long;
using namespace std;

const ll MOD = 1000000007;

int main(){
  int n; cin >> n;
  ll ans = 0;
  ll sum = 0;
  rep(i,n){
    ll a; cin >> a;
    ans += a * sum % MOD; ans %= MOD;
    sum += a; sum %= MOD;
  }
  cout << ans << endl;
  return 0;
}

