#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
template <typename T>
bool PN(T x){ if (x <= 1) return false; if (x == 2) return true; for (int i = 2; i < sqrt(x) + 1; i++) if (x % i == 0) return false; return true;}

const ll MOD = 1e9+7;
long long Comb(int n, int i){long long ans = 1; if(i>n || i < 0) return 0; if(i == 0 || i == n) return 1; else {for(int j = 1; j <= i; ++j){ans *=(n+1-j); ans /= j; ans %= MOD;} }return ans;}
template<typename T> T gcd(T a, T b){if(b == 0) return a;else return gcd(b, a%b);}
template<typename T> T lcm(T a, T b){if(b > a) swap(a, b); T g = gcd(a, b);return a / g * b;}

void solve(){
  int n; cin >> n;
  ll a[n];
  ll sums[n];
  ll sum = 0;
  rep(i, n) {
    cin >> a[i];
    sum += a[i];
  }
  rep(i, n){
    if(i == 0) sums[i] = sum - a[i];
    else {
      sums[i] = sums[i-1] -a[i];
    }
  }
  ll ans = 0;
  rep(i, n){
    sums[i] %= MOD;
    a[i] %= MOD;
    ans += a[i] * sums[i];
    ans %= MOD;
    // cout << sums[i] << endl;
  }
  cout << ans << endl;
}

int main(void){
  solve();
  return 0;
}
