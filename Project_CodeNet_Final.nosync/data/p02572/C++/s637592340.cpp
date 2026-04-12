#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

const ll MOD = 1000000007;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  ll sum = 0;
  ll par = 0;
  rep(i,n){
    cin >> a[i];
    par += a[i]*a[i];
    par %= MOD;
    sum += a[i];
    sum %= MOD;
  }
  ll ans = (sum*sum)%MOD;
  ans -= par;
  ans *= 500000004;
  ans %= MOD;
  ans = (ans+MOD)%MOD;
  cout << ans << endl;
}
