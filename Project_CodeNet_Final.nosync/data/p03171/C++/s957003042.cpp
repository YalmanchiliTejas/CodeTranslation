#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b)-1; i >= (a); --i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pii> vii;

const int N = 3123;
vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(N, vector<ll>(2, -141222)));
int n;
vector<ll> a(N);

ll solve(int l, int r, int id) {
  int c = id ? -1 : 1;
  if (l==r) return c*a[l];
  if (dp[l][r][id] != -141222) return dp[l][r][id];
  if (id) return dp[l][r][id] = min(c*a[l]+solve(l+1,r,id^1), c*a[r]+solve(l,r-1,id^1));
  else    return dp[l][r][id] = max(c*a[l]+solve(l+1,r,id^1), c*a[r]+solve(l,r-1,id^1));
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  cin >> n;
  rep(i,0,n) cin >> a[i];


  cout << solve(0,n-1,0) << '\n';

}