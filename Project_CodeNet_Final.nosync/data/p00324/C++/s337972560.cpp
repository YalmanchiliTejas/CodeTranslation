
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

#define pb push_back
#define rep(i, a, n) for(int i = (a); i < (n); i++)
#define dep(i, a, n) for(int i = (a); i >= (n); i--)
#define mod 1e9+7

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

int main() {
  ll n, g;
  cin >> n;
  ll a[n] = {};
  map<ll, ll> mp;
  cin >> g;
  mp[0] = -1;
  mp[g] = 0;
  ll ans = 0;
  if(g == 0) ans = 1, mp[g] = -1;
  rep(i, 1, n) {
    ll d;
    cin >> d;
    g += d;
    if(mp.count(g)) {
      ans = max(ans, i - mp[g]);
    }else mp[g] = i;
  }
  cout << ans << endl;
}