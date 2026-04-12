#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

struct item { ll weight, value; };

const ll INF = 1LL << 50;

vector<ll> travel_time(vector<ll> X, vector<ll> Y, ll N) {
  vector<vector<ll>> dp(1 << N, vector<ll>(N, INF));
  REP(i, 0, N) dp[1 << i][i] = abs(X[i]) + abs(Y[i]);
  REP(s, 0, 1 << N) REP(i, 0, N) if(s & (1 << i)) {
    REP(j, 0, N) if(!(s & (1 << j))) {
      dp[s | (1 << j)][j] = min(dp[s | (1 << j)][j], dp[s][i] + abs(X[i] - X[j]) + abs(Y[i] - Y[j]));
    }
  }

  vector<ll> t(1 << N, INF);
  REP(s, 0, 1 << N) REP(i, 0, N) t[s] = min(t[s], dp[s][i] + abs(X[i]) + abs(Y[i]));
  return t;
}

vector<ll> profit(vector<vector<ll>> weight, vector<vector<ll>> value, vector<ll> L, ll N, ll W) {
  vector<ll> ret(1 << N, 0);
  REP(s, 0, 1 << N) {
    vector<ll> dp(W + 1, 0);
    dp[0] = 0;
    REP(i, 0, N) if(s & (1 << i)) REP(j, 0, L[i]) {
      REP(w, 0, W + 1) if(w + weight[i][j] <= W) {
        dp[w + weight[i][j]] = max(dp[w + weight[i][j]], dp[w] + value[i][j]);
      }
    }
    REP(i, 0, W + 1) ret[s] = max(ret[s], dp[i]);
  }
  return ret;
}

int main(void) {
  ll N, M, W, T;
  cin >> N >> M >> W >> T;
  map<string, item> items;
  REP(i, 0, M) {
    string S;
    cin >> S;
    cin >> items[S].weight >> items[S].value;
  }
  vector<ll> L(N), X(N), Y(N);
  vector<vector<ll>> weight(N), value(N);
  REP(i, 0, N) {
    cin >> L[i] >> X[i] >> Y[i];
    weight[i].resize(L[i]);
    value[i].resize(L[i]);
    REP(j, 0, L[i]) {
      string S;
      ll x;
      cin >> S >> x;
      weight[i][j] = items[S].weight;
      value[i][j] = items[S].value - x;
    }
  }

  vector<ll> t = travel_time(X, Y, N);
  vector<ll> p = profit(weight, value, L, N, W);

  vector<ll> dp(T + 1, 0);
  dp[0] = 0;
  REP(i, 0, 1 << N) {
    REP(j, 0, T + 1) if(j + t[i] <= T) {
      dp[j + t[i]] = max(dp[j + t[i]], dp[j] + p[i]);
    }
  }

  ll ans = 0;
  REP(i, 0, T + 1) ans = max(ans, dp[i]);
  cout << ans << endl;
}
