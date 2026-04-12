#include <regex>
#include "bits/stdc++.h"
#define FOR(i, s, e) for (int i = int(s); i < int(e); ++i)
#define REP(i, e) FOR(i, 0, e)
#define INF (INT_MAX / 2)
#define LINF (LLONG_MAX / 2)
#define EPS (1.0e-8)
#define mkpr make_pair
const int MGN = 10;
const int ARY_SZ_MAX = (int)1e7;
using namespace std;
using ll = long long; using ull = unsigned long long;
using vi = vector<int>; using vvi = vector<vi>;
using vc = vector<char>; using vvc = vector<vc>;
using vb = vector<bool>; using vvb = vector<vb>;
using vl = vector<ll>; using vvl = vector<vl>;
using vd = vector<double>; using vs = vector<string>;
using pii = pair<int, int>; using pll = pair<ll, ll>; using psl = pair<string, ll>;


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);


  int N,M; cin>>N>>M;

  string ans = N==M ? "Yes" : "No";
  cout << ans << endl;


  return 0;
}
