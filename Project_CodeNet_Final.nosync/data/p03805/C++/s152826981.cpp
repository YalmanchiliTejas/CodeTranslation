#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;

ll solve(const vector<vector<int>> &adj, int k, int S) {
  int N = adj.size();
  if(S == (1 << N) - 1) return 1LL;
  ll res = 0LL;
  for(int e: adj[k]) {
    if((S >> e) & 1) continue;
    res += solve(adj, e, S + (1 << e));
  }
  return res;
}

int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> adj(N);
  REP(i,M) {
    int a, b;
    cin >> a >> b; --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  cout << solve(adj, 0, 1) << endl;
  return 0;
}

