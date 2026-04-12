#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define REP(i, n) FOR(i, 0, n)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define RREP(i, n) RFOR(i, n, 0)
#define MFOR(i, m) for(auto i=(m).begin();i!=(m).end();i++)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((int)(x).size())

typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1 << 22;

template<typename T>
void printv(vector<T> const& s) {
  REP(i, SZ(s)) {
    cout << s[i] << " ";
  }
  cout << endl;
}

vll s;
vll p;

ll solve(ll n, ll k) {

  if(n == 0) return 1;
  if(k == 1) return 0;
  else if(k <= 1 + s[n-1]) return solve(n-1, k-1);
  else if(k == 2 + s[n-1]) return solve(n-1, s[n-1]) + 1;
  else if(k <= 2 + 2 * s[n-1]) return p[n-1] + 1 + solve(n-1, k - 2 - s[n-1]);
  else if(k == s[n]) return 2 * p[n-1] + 1;
}

int main () {
  cin.tie(0);
  cout << setprecision(10);

  ll n, k; cin >> n >> k;
  s.resize(n+1);
  p.resize(n+1);
  s[0] = 1;
  p[0] = 1;
  FOR(i, 1, n+1) {
    s[i] = 3 + (s[i-1] * 2);
    p[i] = 1 + (p[i-1] * 2);
  }


  if(n == 0) cout << 1 << endl;
  else cout << solve(n, k) << endl;
}
