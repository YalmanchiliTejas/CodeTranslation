// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using TP = tuple<ll,ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
}
const ll MOD = 1e9+7;
signed main(){
  init_io();
  ll n;
  cin >> n;
  vector<ll> a(n),sum(n+1,0);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i=0;i<n;i++){
    sum[i+1] += sum[i] + a[n-1-i];
    sum[i+1] %= MOD;
  }
  ll ans = 0;
  for(int i=0;i<n;i++){
    ans += (a[i] * sum[n-1-i])%MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}
