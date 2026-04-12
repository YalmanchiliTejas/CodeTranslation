#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) begin(v), end(v)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using pint = pair<int, int>;
using tint = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

int coin[10];
int change[1<<10];
int dp[100010];

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int N, M;
  while(cin >> N >> M, N || M) {
    rep(i, N) cin >> coin[i];
    rep(i, 1<<N) {
      int c = 0;
      rep(j, N) if((i>>j)&1) c += coin[j];
      change[i] = c;
    }
    fill(dp, dp + 100010, inf);
    dp[0] = 0;
    rep(i, 1<<N) {
      for(int j = 0; j+change[i] <= M; j++) {
	chmin(dp[j+change[i]], dp[j] + 1);
      }
    }
    cout << dp[M] << endl;
  }

  return 0;
}