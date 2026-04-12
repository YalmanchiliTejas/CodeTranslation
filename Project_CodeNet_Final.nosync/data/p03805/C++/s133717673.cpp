#include <bits/stdc++.h>
#if 1
#define int long long
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define stoi stoll
#else
#define MAX INT_MAX
#define MIN INT_MIN
#endif
#define ALL(obj) (obj).begin(), (obj).end()
#define fi first
#define se second
const int NIL = -1;
const int MOD = 1000000007;
#define REP(i,n) for (int i=0; i < (n); ++i)
#define FOR(i,a,b) for (int i=(a); i < (b); ++i)
using namespace std;

int pow(int x, int n) {int res=1; while(n){if(n&1)res*=x;x*=x;n>>=1;} return res;}
int get_gcd(int a, int b){while(1){if (a < b) swap(a, b); if (b == 0) return a; a %= b;}}
int get_lcm(int a, int b){return a * b / get_gcd(a, b);}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

//-------------------------テンプレここまで-------------------------//

signed main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  REP(i, M) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<int> p(N-1);
  REP(i,N-1) p[i] = i + 1;

  int ans = 0;
  do {
    p.push_back(0);

    bool is_good = true;
    for (int i = N-1; i > 0; i--) {
      if (find(ALL(G[p[i]]), p[i-1]) == G[p[i]].end()) {
        is_good = false;
        break;
      }
    }
    if (is_good) ans++;

    p.pop_back();
  } while(next_permutation(ALL(p)));

  cout << ans << endl;

  return 0;
}
