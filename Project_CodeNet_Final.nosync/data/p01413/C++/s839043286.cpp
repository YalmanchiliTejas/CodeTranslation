#include <bits/stdc++.h>
using namespace std;

#define INF 0x33433433
using LLI = long long int;

int N;
int M;
int W;
int T;
int P[114];
int V[114];
int L[114];
int X[114];
int Y[114];
int Q[114][114];
char buf[114514];
LLI dp[1 << 9][11451];
LLI dp2[1 << 9][114];
LLI dp3[11451];

string S[114];
string R[114][114];
map<string, int> rev;

int Dist(int u, int v) {
  return abs(X[u]-X[v]) + abs(Y[u]-Y[v]);
}

int main() {
  scanf("%d%d%d%d", &N, &M, &W, &T);
  for (int i=0; i<M; i++) {
    scanf("%s%d%d", buf, &V[i], &P[i]);
    S[i] = buf;
    rev[S[i]] = i;
  }

  for (int i=0; i<N; i++) {
    scanf("%d%d%d", &L[i], &X[i], &Y[i]);
    for (int j=0; j<L[i]; j++) {
      scanf("%s%d", buf, &Q[i][j]);
      R[i][j] = buf;
    }
  }

  int lim = 1 << N;
  for (int st=0; st<lim; st++) {
    map<string, int> vs;
    for (int i=0; i<N; i++) {
      if (!(st >> i & 1)) continue;
      for (int j=0; j<L[i]; j++) {
        if (!vs.count(R[i][j])) vs[R[i][j]] = Q[i][j];
        else vs[R[i][j]] = min(vs[R[i][j]], Q[i][j]);
      }
    }

    for (auto &itr : vs) {
      string s = itr.first;
      int w = V[rev[s]];
      int p = P[rev[s]] - itr.second;

      for (int i=0; i<=W-w; i++) {
        dp[st][i+w] = max(dp[st][i+w], dp[st][i]+p);
      }
    }

    for (int i=0; i<W; i++) {
      dp[st][i+1] = max(dp[st][i+1], dp[st][i]);
    }
  }

  fill(dp2[0], dp2[lim], INF);
  dp2[0][N] = 0;
  for (int st=0; st<lim; st++) {
    for (int v=0; v<=N; v++) {
      for (int i=0; i<=N; i++) {
        int nst = st;
        if (i != N) nst |= (1 << i);
        dp2[nst][i] = min(dp2[nst][i], dp2[st][v] + Dist(i, v));
      }
    }
  }

  for (int t=0; t<T; t++) {
    for (int st=0; st<lim; st++) {
      int nt = t+dp2[st][N];
      if (T < nt) continue;
      dp3[nt] = max(dp3[nt], dp3[t] + dp[st][W]);
    }
  }

  LLI ans = 0;
  for (int t=0; t<=T; t++) {
    ans = max(ans, dp3[t]);
  }
  printf("%lld\n", ans);
}