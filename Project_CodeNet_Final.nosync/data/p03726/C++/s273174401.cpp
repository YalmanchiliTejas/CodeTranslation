#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORD(i,b,a) for (int i = (int)(b) - 1; i >= a; --i)
#define REP(i,N) FOR(i,0,N)
#define st first
#define nd second
#define pb push_back

typedef pair<int, int> PII;
typedef long long LL;

vector<int> adj[222222];
int m[222222];

void go(int v, int p) {
  for (int u: adj[v]) if (u != p) {
    go(u, v);
    if (!m[u] && !m[v]) {
      m[u] = v;
      m[v] = u;
    }
  }
}

int main() {
  int N;
  scanf("%d", &N);
  REP(i,N-1) {
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].pb(b);
    adj[b].pb(a);
  }
  go(1,-1);
  bool ok = true;
  FOR(i,1,N+1) ok = ok && m[i];
  printf(ok ? "Second\n" : "First\n");
}
