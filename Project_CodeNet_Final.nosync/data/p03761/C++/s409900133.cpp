#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define pa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
#define pb push_back

using ll = long long;
using namespace std;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
const int INFint = 1e9;
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

int main(){
  int N;
  string s[100];
  cin>>N;
  rep(i,N) cin>>s[i];
  int l[100][30] = {0};
  rep(i,N){
    for (int j(0);j<int(s[i].size());j++){
      l[i][s[i][j]-'a']++;
    }
  }
  int ans[30] = {0};
  rep(i,30){
    int mini(100);
    for (int j(0);j<N;j++){
      mini = min(mini,l[j][i]);
    }
    ans[i] = mini;
  }
  //rep(i,30) cout << ans[i] <<" ";
  for(int i(0);i<30;i++){
    cout << string(ans[i],'a'+i);
  }
  cout << endl;
  return 0;
}
