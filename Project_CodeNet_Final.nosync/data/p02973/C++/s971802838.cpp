#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define fst first
#define snd second
#define pf push_front
#define pb push_back
#define eb emplace_back
#define ALL(obj) (obj).begin(), (obj).end()
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
//#define int long long int
const int MOD = 1000000007;
const ll LINF = (ll)1e18 - 1;
const int INF = 1e9 - 1;
const double EPS = 0.000000001;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  VI a(n);
  multiset<int> m;
  rep(i, n){
    cin >> a[i];
  }
  m.insert(a[0]);
  for(int i = 1; i < n; i++){
    auto ite = m.lower_bound(a[i]);
    if(ite == m.begin()) m.insert(a[i]);
    else{
      ite--;
      m.erase(ite);
      m.insert(a[i]);
    }
  }
  out(m.size());
  return 0;
}
