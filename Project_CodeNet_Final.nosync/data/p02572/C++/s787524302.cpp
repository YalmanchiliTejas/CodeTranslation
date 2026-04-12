#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  int n;
  cin >> n;
  const ll MOD = (ll)pow(10,9)+7;
  vector<ll> a(n);
  vector<ll> p(n);
  rep(i,n){
    cin >> a[i];
    if(i == 0) p[i] = a[i];
    else{
      p[i] = p[i-1] + a[i];
      p[i] %= MOD;
    }
  }
  ll ans = a[0]*a[1];
  ans %= MOD;
  for(int i=2;i<n;i++){
    ans += p[i-1]*a[i];
    ans %= MOD;
  }
  cout << ans << endl;
}
