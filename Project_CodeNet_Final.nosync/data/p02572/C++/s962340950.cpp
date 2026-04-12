/*

*/
#include<bits/stdc++.h>

using namespace std;
using ll=long long;
#define rep2(i, a, n) for(int i = (a); i < (n); i++)
#define rep(i, n) rep2(i,0,n)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int main(){
  cin.tie(nullptr);ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<ll> b(n + 1, 0);
  int mod = 1000000007;

  rep(i,n){
    cin >> a[i];
    b[i + 1] = b[i] + a[i];
  }

  ll ans = 0;

  rep(i,n){
    ll sum = (b[n] - b[i + 1]) % mod;

    ans += a[i] * sum;
    ans %= mod;
  }

  cout << ans << endl;
}