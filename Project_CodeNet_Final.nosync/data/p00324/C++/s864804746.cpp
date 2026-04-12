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
  int n;
  cin >> n;
  ll r[200005] = {};
  map<ll, int> mp;
  int ans = 0;
  for(int i = 1; i <= n; i++) cin >> r[i];
  for(int i = 1; i <= n; i++) r[i] += r[i - 1];

  for(int i = 0; i <= n; i++) {
    if(mp.count(r[i])) {
      ans = max(ans, i - mp[r[i]]);
    }else mp[r[i]] = i;
  }

  cout << ans << endl;
}