#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define ll long long
#define pii pair < int, int >
#define fr first
#define sc second
#define mk make_pair
#define sz(s) (int)s.size()
#define all(s) s.begin(), s.end()
#define ok cerr << "ok\n";
#define whatis(x) cerr << #x << " = " << x << endl;

const int N = (int)1e5 + 7;
const int inf = (int)1e9 + 7;

main() {
  int n, k;
  scanf("%d %d", &n, &k);
  if (k == 0) {
    cout << n * 1LL * n;
    return 0;
  }
  ll ans = 0;
  int add = k + 1;
  ll ad = 1;
  for (int i = k + 1; i <= n; i++) {
    for (int j = k; j <= n; j += add) {
//      cerr << j << ' ';
      if (j + ad - 1 > n) {
        ans += (n - j + 1);
        break;
      }
      ans += ad;
      j += (ad - 1);
    }
    ad++;
  }
  cout << ans;
}
