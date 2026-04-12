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
  int t[300001];
  rep(i, 0, n) cin >> t[i];

  int ik = 0;
  rep(i, 0, n) {
    if(i > ik) {
      cout << "no" << endl;
      return 0;
    }
    ik = max(ik, i + t[i] / 10);
  }
  ik = 0;
  dep(i, n - 1, 0) {
    if((n - 1) - i > ik) {
      cout << "no" << endl;
      return 0;
    }
    ik = max(ik, (n - 1) - i + t[i] / 10);
  }

  cout << "yes" << endl;
}

