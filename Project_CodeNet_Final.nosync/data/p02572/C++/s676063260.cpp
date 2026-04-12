#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll mod=1000000007;
int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  vector<ll> s(n);
  rep(_i,n-1){
    int i=n-_i-2;
    s[i] = (s[i+1]+a[i+1])%mod;
  }
  ll ans = 0;
  rep(i,n) ans = (ans+a[i]*s[i])%mod;
  cout << ans << endl;
}
