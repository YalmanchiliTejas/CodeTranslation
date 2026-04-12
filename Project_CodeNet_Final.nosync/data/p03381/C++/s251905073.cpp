#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define pb push_back
#define rep(i, a, n) for(int i = (a); i < (n); i++)
#define dep(i, a, n) for(int i = (a); i >= (n); i--)
#define mod (ll)(1e9+7)
#define int ll

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

signed main() {
  int n;
  cin >> n;
  int a[200001] = {}, b[200001];
  rep(i, 0, n) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(a, a + n);
  int t = a[n / 2 - 1], tt = a[n / 2];
  rep(i, 0, n) {
    if(b[i] <= t) {
      cout << tt << endl;
    }else {
      cout << t << endl;
    }
  }
}
