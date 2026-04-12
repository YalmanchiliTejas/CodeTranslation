#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;
#define MOD 1000000007

int main(){
  ll n; cin >> n;
  ll sum = 0;
  vector<ll> a(n);

  for(ll i=0;i<n;i++){
    cin >> a.at(i);
    sum += a.at(i);
  }

  ll ans = 0;

  for(ll i=0;i<n;i++){
    ans += ((a.at(i)%MOD)*((sum-a.at(i))%MOD))%MOD;
    sum -= a.at(i);
  }

  cout << ans%MOD << endl;

}
