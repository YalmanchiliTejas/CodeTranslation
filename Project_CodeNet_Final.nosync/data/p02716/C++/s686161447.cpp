#include <bits/stdc++.h>
using namespace std;

#define sz(x) int(x.size())
#define pii pair<int, int>
#define All(x) (x).begin(), (x).end()
#define mp make_pair
#define Task "abc"

typedef long long ll;
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;

ll f[maxn][3];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(NULL);
//  freopen(Task".inp", "r", stdin); freopen(Task".out", "w", stdout);
  int n; cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i){
    cin >> a[i];
  }
  ll inf = ll(1e18);
  for (int i = 0; i <= n; ++i)
  for (int j = 0; j < 3; ++j) f[i][j] = -inf;
  f[1][0] = -inf; f[1][1] = 0; f[1][2] = a[1];
  f[2][0] = 0; f[2][1] = max(a[1], a[2]);
  for (int i = 3; i <= n; ++i){
    int l = i/2 - 1, r = (i+1) / 2;
    int opl = (i-2)/2 - 1, opr = (i-1) / 2;
    for (int j = opl; j <= opr; ++j){
      if (l <= j + 1 && j + 1 <= r) f[i][j - l + 1] = max(f[i][j - l + 1], f[i-2][j - opl] + a[i]);
    }
    opl = (i-1)/2 - 1, opr = i / 2;
    for (int j = opl; j <= opr; ++j){
      if (l <= j && j <= r) f[i][j - l] = max(f[i][j - l], f[i-1][j - opl]);
    }
  }
  cout << f[n][1];
return 0;
}


