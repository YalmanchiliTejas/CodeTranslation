#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

int main() {
    cin.tie(0);
    cout << fixed << setprecision(10);

    int n; cin >> n;
    vector<ll> s(n);
    for(int i=0;i<n;++i) {
      cin >> s[i];
    }

    ll ans = s[n-1];

    for(int i=1;i<=n-2;++i) {
      ll ma = s[n-1];
      vector<bool> sel(n);
      sel[0] = sel[n-1] = true;
      ll su = s[n-1];
      int l = 0, r = n-1;
      // cout << endl;
      // cout << i << endl;
      while(1) {
        
        l += i;
        r -= i;
        if(l > n-1 || r < 0 || r <= i || l == r || sel[l] || sel[r]) break;
        su += s[l] + s[r];
        sel[l] = sel[r] = true;
        ma = max(ma, su);
        // printv(sel);
        // cout << su << endl;
      }
      ans = max(ans, ma);
    }
    cout << ans << endl;
}