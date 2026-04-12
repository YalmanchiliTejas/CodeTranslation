//Daniel Grzegorzewski
#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define MP make_pair
#define PB push_back
#define ST first
#define ND second
#define int long long

using namespace std;

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef long long LL;

void init_ios() {
     ios_base::sync_with_stdio(0);
     cin.tie(0);
}

const int MOD = (int)1e9 + 7;
const int N = (int)1e4 + 3;

int d, mniej[N][103], pref[N];
string k;

signed main() {
  init_ios();
  cin >> k >> d;
  int n = k.size();
  pref[0] = (int)(k[0]-'0');
  for (int i = 0; i < pref[0]; ++i)
    mniej[0][i%d] = (mniej[0][i%d]+1)%MOD;
  for (int i = 1; i < n; ++i) {
    int cy = (int)(k[i]-'0');
    pref[i] = cy;
    if (i > 0)
      pref[i] = (pref[i]+pref[i-1])%d;
    for (int j = 0; j <= 9; ++j) {
      for (int re = 0; re < d; ++re) {
        int now = (j+re)%d;
        mniej[i][now] = (mniej[i][now]+mniej[i-1][re])%MOD;
      }
    }
    for (int j = 0; j < cy; ++j) {
      int now = (j+pref[i-1])%d;
      mniej[i][now] = (mniej[i][now]+1)%MOD;
    }
  }
  int res = mniej[n-1][0]-1;
  if (res < 0)
    res += MOD;
  if (pref[n-1]%d == 0)
    res = (res+1)%MOD;
  cout<<res<<"\n";
}