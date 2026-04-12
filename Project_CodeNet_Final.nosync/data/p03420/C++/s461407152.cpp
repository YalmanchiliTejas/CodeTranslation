#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define repr(i,n,m) for(int i=m; i<n; i++)
#define MAX 100
#define MOD 1000000007
#define pb push_back
#define debug(x) cout << x << endl;
#define END cout << endl;
#define sorti(x) sort(x.begin(), x.end())

int main() {
  int n,k; cin >> n >> k;
  ll res = 0;

  if (k == 0) {
    ll res = (ll)pow(n,2);
    cout << res << endl;
    return 0;
  }

  for (int i = k+1; i <= n; ++i) {
    ll num = i - k;
    ll cnt = floor((double) n / i);
    res += cnt * num;

    ll pos = k + (i * cnt);
    if (pos <= n) {
      res += n - pos + 1;
    }
  }

  cout << res << endl;
}