#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define resz(v, ...) (v).clear(), (v).resize(__VA_ARGS__)
#define reps(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using Pi = pair<int, int>;
using Ti = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

int N, M, W, T;
map<string, Pi> data;
vector<Pi> city;
vector<map<string, int>> buy;

int dist(Pi a, Pi b) {
  return llabs(a.first-b.first)+llabs(a.second-b.second);
}

int tsp[7][1<<7];
int calcTSP(int bit, int now, int S) {
  int& res = tsp[now][bit];
  if(~res) return res;
  if(bit == S) return dist(city[now], Pi(0, 0));
  res = inf;
  for(int i = 0; i < N; i++) {
    if((bit>>i)&1) continue;
    if((S>>i)&1) chmin(res, calcTSP(bit|1<<i, i, S)+dist(city[now], city[i]));
  }
  return res;
}
int knap[1<<7][10010];
void calcKnapsack() {
  memset(knap, -1, sizeof(knap));
  for(int S = 0; S < 1<<N; S++) {
    knap[S][0] = 0;
    for(int i = 0; i < N; i++) {
      if(!((S>>i)&1)) continue;
      for(auto&& p : buy[i]) {
	int w = data[p.first].first;
	int sp = data[p.first].second;
	int bp = p.second;
	for(int j = 0; j <= W-w; j++) {
	  if(knap[S][j] == -1) continue;
	  chmax(knap[S][j+w], knap[S][j]+sp-bp);
	}
      }
    }
    for(int i = 0; i < W; i++) chmax(knap[S][i+1], knap[S][i]);
  }
}

int dp1[1<<7];
int dp[10010];
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> N >> M >> W >> T;
  for(int i = 0; i < M; i++) {
    string s; int v, p;
    cin >> s >> v >> p;
    data[s] = Pi(v, p);
  }
  buy.resize(N);
  for(int i = 0; i < N; i++) {
    int l, x, y;
    cin >> l >> x >> y;
    city.push_back(Pi(x, y));
    for(int j = 0; j < l; j++) {
      string r; int q;
      cin >> r >> q;
      buy[i][r] = q;
    }
  }
  fill(dp1, dp1+(1<<7), inf);
  for(int S = 0; S < 1<<N; S++) {
    memset(tsp, -1, sizeof(tsp));
    for(int i = 0; i < N; i++) {
      if((S>>i)&1) chmin(dp1[S], calcTSP(1<<i, i, S)+dist(city[i], Pi(0, 0)));
    }
  }
  calcKnapsack();
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  for(int i = 0; i <= T; i++) {
    for(int S = 0; S < 1<<N; S++) {
      if(dp[i] == -1) continue;
      if(i+dp1[S] <= T) chmax(dp[i+dp1[S]], dp[i]+knap[S][W]);
    }
  }
  int ans = 0;
  for(int i = 0; i <= T; i++) chmax(ans, dp[i]);
  cout << ans << endl;

  return 0;
}