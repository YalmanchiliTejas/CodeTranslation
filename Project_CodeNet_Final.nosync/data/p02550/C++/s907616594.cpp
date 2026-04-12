#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define popcnt __builtin_popcount
#define getBit(x, k) ((x >> k) & 1)
#define all(x) (x).begin(),(x).end()
// ---------------------------------

void Main() {
  int n, x, mod;
  cin >> n >> x >> mod;
  vector<int> val(100001);
  val[1] = x;
  map<int, int> mem;
  mem[x] = 1;
  int t = x, ans = x;
  for (int i = 2; i <= n; i++) {
    t = (t * t) % mod;
    if (mem[t]) {
      int d = i - mem[t];
      int r = n - i + 1;
      int c = 0;
      for (int j = mem[t]; j < i; j++) {
        c += val[j];
      }
      ans += (r / d) * c;
      for (int j = mem[t]; j <= mem[t] + r % d - 1; j++) {
        ans += val[j];
      }
      cout << ans << '\n';
      return;
    }
    val[i] = t;
    mem[t] = i;
    ans += t;
  }
  cout << ans << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  cerr << "i love ------- <3 \n";
#endif
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  // cin >> T;
  while (T--) Main();
}
