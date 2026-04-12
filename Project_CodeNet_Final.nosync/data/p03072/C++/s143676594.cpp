#include <bits/stdc++.h>
using namespace std;

#define MEM(a, b) memset(a, b, sizeof a);
#define REP(i, k) for(int i = (0); i < (k); i++ )

#define ALL(cont) cont.begin(), cont.end()
#define RALL(cont) cont.begin(), cont.end()
#define FOREACH(it, l) for(auto it=l.begin(); it != l.end(); it++)
#define mp make_pair
#define pb push_back
#define debug puts("FANGO")
#define INF (int)MAX_INT
#define EPS (int)1e-9
#define PI acos(-1)
#define MOD 1000000007

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef long long int32;
typedef unsigned long long uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

template <class T>
T sqr(T val) {
  return val * val;
}

void solve(__attribute__((unused)) int tc = 0) {
  int n;
  cin >> n;
  int maxi = -1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    if (h >= maxi) {
      maxi = h;
      ans++;
    }
  }
  cout << ans << "\n";
  return;
}

int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  /*int TC;
  cin >> TC;
  REP(tc, TC) {
    solve(tc);
  }*/
  solve();
}
