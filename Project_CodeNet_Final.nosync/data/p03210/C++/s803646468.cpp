#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define pb push_back
#define rep(i, n) for(int i = 0; i < (n); i++)
#define dep(i, a, n) for(int i = a; i >= (n); i--)
#define FOR(i, a, n) for(int i = a; i < (n); i++)
#define mod (ll)(1e9+7)
#define int ll
#define INF 100000000

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

signed main() {
	int old;
  cin >> old;
  if (old == 7 || old == 5 || old == 3) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
	return 0;
}
