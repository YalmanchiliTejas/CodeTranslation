#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); i++)
typedef long long ll;

int main()
{
  ll n; cin >> n;
  string s; cin >> s;
  rep(k, 4) {
    vector<int> a(n, 0);
    rep(i, 2) a[i] = (k>>i)&1;

    for (int i=1; i<n; i++) {
      int l = (i-1+n)%n;
      int r = (i+1)%n;
      int t = s[i]=='o' ? 0 : 1;
      a[r] = a[l]^a[i]^t;
    }
    if ((a[n-1]^a[1]^(s[0]=='o'?0:1)) == a[0]
        && (a[0]^a[2]^(s[1]=='o'?0:1)) == a[1]) {
      rep(j, n) {
        if (a[j]) cout << "W";
        else cout << "S";
      }
      cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;

  return 0;
}
