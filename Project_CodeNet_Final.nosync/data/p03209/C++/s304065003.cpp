#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
typedef long long ll;
using namespace std;

void solve(){
  ll n, x, l = 0, r, ans = 0; cin >> n >> x;
  x--;
  vector<ll> y(n + 1), sum(n + 1);
  y[0] = 1;
  sum[0] = 1;
  for(int i = 1; i <= n; i++){
    y[i] = y[i - 1] * 2 + 3;
    sum[i] = sum[i - 1] * 2 + 1;
  }
  r = y[n] - 1;
  for(int i = n; i >= 0; i--){
    ll mid = (l + r) / 2;
    if(x == mid){
      ans += sum[i] / 2 + 1;
      break;
    }
    if(x < mid){
      l++;
      r = mid - 1;
    }
    else{
      ans += sum[i] / 2 + 1;
      l = mid + 1;
      r--;
    }
  }
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}
