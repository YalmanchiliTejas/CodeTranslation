#include <bits/stdc++.h>

#define int long long int
#define main signed main()
#define bye return 0

#define rep(i, n) for (int i = 0; i < (n); i++)
#define each(p, v) for (auto p = (v).begin(); p != (v).end(); p++)
#define all(v) (v).begin(), (v).end()
#define sum(v) accumulate(all(v), 0)
#define cinv(v, n) rep(i, n) cin >> v[i]
#define prec(n) fixed << setprecision(n)
#define stlice(s, l) substr(s, s + l + 1)
#define odd(n) ((n) % 2)
#define even(n) (!((n) % 2))

#define INF 1e9
#define MOD (1e9 + 7)

#define pb push_back
#define mt make_tuple
#define fi first
#define se second
#define str string
#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<str>

using namespace std;

main {
  int h, w;
  cin >> h >> w;
  int c = 0;
  rep(i, h) {
    str a;
    cin >> a;
    rep(j, a.size()) c += a[j] == '#';
  }
  cout << (h + w - 1 == c ? "Possible" : "Impossible") << endl;
  bye;
}
