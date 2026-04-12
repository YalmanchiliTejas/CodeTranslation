#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

int INF = 1ll << 30;

void chmin(int &a, int b){
  if(a > b)
    a = b;
}

int main(){
  ll n;
  cin >> n;
  vl a(n);
  vl sum(n);
  sum[0] = 0;
  ll mod = 1000000007;

  rep(i, 0, n){
    cin >> a[i];
  }
  sum[0] = a[0];
  rep(i, 1, n){
    sum[i] = (sum[i-1] + a[i]) % mod;
    sum[i] %= mod;
  }
  
  ll ans = 0;
  
  rep(i, 1, n){
    ans += (a[i] * sum[i-1]) % mod;
    ans %= mod;
  }
  
  if(ans < 0)
    ans += mod;
  
  cout << ans << endl;
  
  return 0;
  
}