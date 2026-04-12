#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define pa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
#define pb push_back

using ll = long long;
using namespace std;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
const int INFint = 2e9;
const ll INFll = 1e18;
ll MOD=1e9+7;

ll gcd(ll a, ll b) { return __gcd(a,b); } //最大公約数
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; } //最大公倍数

// aのn乗をMODで割りながら計算する
ll modpow(ll a, ll n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % MOD;
    a = a * a % MOD;
    n >>= 1; // right shift
  }
  return res;
}

// MODを法としたaの逆元を計算する
ll modinv(ll a) {
  return modpow(a, MOD - 2);
}
map<int,int> prime_factor(int n){
  map<int,int> res;
  for (int i(2);i*i<=n;i++){
    while(n%i==0){
      ++res[i];
      n/=i;
    }
  }
  if (n!=1) res[n]=1;
  return res;
}

int main(){
  int N;
  cin>>N;
  vector<int> a(N);
  rep(i,N) cin>>a[i];
  reverse(a.begin(),a.end());
  int dp[100001];
  fill(dp,dp+N+1,INFint);
  for (int i(0);i<N;i++){
    *upper_bound(dp,dp+N,a[i]) = a[i];
  }
  cout << lower_bound(dp,dp+N,INFint) - dp << endl;
  return 0;
}
