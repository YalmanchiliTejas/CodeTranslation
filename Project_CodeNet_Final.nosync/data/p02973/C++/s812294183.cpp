#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < n; i++)
using namespace std;

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  deque<int> d;
  rep(i, n){
    ll p = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
    if (p == 0){
      d.push_front(a[i]);
    }
    else d[p-1] = a[i];
  }
  ll ans = d.size();
  cout << ans << endl;
  return 0;
}