#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1LL << 58;


int N, M, W, T;
map< string, int > beet;
int V[7], P[7], X[7], Y[7];
int dp[1 << 7][10001];
int visit[1 << 7][7], fact[1 << 7];
int dp2[10001];
vector< pair< int, int > > latte[7];

int get_dist(int a, int b, int c, int d)
{
  return (abs(a - c) + abs(b - d));
}

signed main()
{
  cin >> N >> M >> W >> T;
  for(int i = 0; i < M; i++) {
    string s;
    cin >> s >> V[i] >> P[i];
    beet[s] = i;
  }

  for(int i = 0; i < N; i++) {
    int L;
    cin >> L >> X[i] >> Y[i];
    for(int j = 0; j < L; j++) {
      string s;
      int v, w;
      cin >> s >> v;
      w = V[beet[s]];
      v = P[beet[s]] - v;
      latte[i].emplace_back(w, v);
    }
  }

  fill_n(*visit, (1 << 7) * 7, INF);
  for(int i = 0; i < N; i++) {
    visit[1 << i][i] = get_dist(0, 0, X[i], Y[i]);
  }
  for(int i = 0; i < 1 << N; i++) {
    for(int j = 0; j < N; j++) {
      if(dp[i][j] == INF) continue;
      for(int k = 0; k < N; k++) {
        if((i >> k) & 1) continue;
        visit[i | (1 << k)][k] = min(visit[i | (1 << k)][k], visit[i][j] + get_dist(X[j], Y[j], X[k], Y[k]));
      }
    }
  }

  fill_n(fact, 1 << 7, INF);
  for(int i = 0; i < 1 << N; i++) {
    for(int j = 0; j < N; j++) {
      fact[i] = min(fact[i], visit[i][j] + get_dist(X[j], Y[j], 0, 0));
    }
  }


  for(int i = 0; i < 1 << N; i++) {
    for(int j = 0; j < N; j++) {
      if((i >> j) & 1) {
        for(auto &p : latte[j]) {
          for(int k = 0; k <= W - p.first; k++) {
            dp[i][k + p.first] = max(dp[i][k + p.first], dp[i][k] + p.second);
          }
        }
      }
    }
  }

  for(int i = 0; i <= T; i++) {
    for(int j = 0; j < 1 << N; j++) {
      if(i + fact[j] > T) continue;
      dp2[i + fact[j]] = max(dp2[i + fact[j]], dp2[i] + dp[j][W]);
    }
  }

  cout << dp2[T] << endl;

}