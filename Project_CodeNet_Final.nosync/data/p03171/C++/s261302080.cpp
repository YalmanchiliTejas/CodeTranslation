#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int a[3010];
ll dp[3010][3010];
bool flg[3010][3010];
ll f(int l, int r){
  if (flg[l][r]) {
    return dp[l][r];
  }
  flg[l][r] = true;

  ll ans;
  if (l==r) {
    ans = a[l];
  } else {
    ans = max( a[l] - f(l+1,r), a[r] - f(l,r-1) );
  }
  return dp[l][r] = ans;
}

int main() {
  int n;
  cin >> n;
  rep(i,n){
    cin >> a[i];
  }
  cout << f(0,n-1) << endl;
}
