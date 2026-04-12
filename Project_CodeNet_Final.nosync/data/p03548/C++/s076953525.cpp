#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define pb push_back
#define rep(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < (n); i++)
#define mod (ll)(1e9+7)
#define int ll

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

signed main() {
	ll x, y, z, sum, count = 0;
  cin >> x >> y >> z;
  sum = z;
  while (x >= sum + z + y) {
    sum += y + z;
    count++;
  }
  cout << count << endl;
}