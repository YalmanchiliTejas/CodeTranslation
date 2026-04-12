#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int) (n); i++)
#define _GLIBCXX_DEBUG

template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

typedef long long ll;
const ll MOD = 1000000007;
const int max_n = 200010;
ll a[max_n], s[max_n];
int n;

int main(){
    cin >> n;
    rep(i, n) cin >> a[i];

    ll ans=0;
    rep(i, n){
        s[i+1] = s[i] + a[i];
    }

    rep(i, n){
        ll tmp = (s[n] - s[i+1]) % MOD;
        ans += tmp * a[i];
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}