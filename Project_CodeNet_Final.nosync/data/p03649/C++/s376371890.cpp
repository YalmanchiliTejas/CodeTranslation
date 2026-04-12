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
signed main(){
  init_io();
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  ll ans = 0;
  while(true){
    ll s = 0;
    for(int i=0;i<n;i++){
      s += a[i]/n;
    }
    if(s==0) break;
    ans += s;
    for(int i=0;i<n;i++){
      a[i] = a[i] - (a[i]/n)*n + (s-a[i]/n);
    }
  }
  cout << ans << endl;
}
