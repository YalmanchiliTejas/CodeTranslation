#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
#define FOR(i, a, b) for(int i = 0; i < (a); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).end()
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
//#define int long long int
const int MOD = 1000000007;
const ll LINF = (ll)1e18 - 1;
const int INF = 1e9 - 1;
const double EPS = 0.000000001;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void print(const vector<int> &v) {
  for(auto x : v) {
    cout << x << " ";
  }
  cout << endl;
}

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  VVI e(n, VI(n, 0));
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    e[a][b] = 1;
    e[b][a] = 1;
  }
  VI ord(n);
  iota(all(ord), 0);
  int ans = 0;
  do {
    if(ord[0] != 0) continue;
    bool flag = true;
    rep(i, ord.size()-1) {
      if(e[ord[i]][ord[i+1]] == 0) {
        flag = false;
        break;
      }
    }
    if(flag) ans++;
  }while (next_permutation(all(ord)));

  out(ans);
  return 0;
}
