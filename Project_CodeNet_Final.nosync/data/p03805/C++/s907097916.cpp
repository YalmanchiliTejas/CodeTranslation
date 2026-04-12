#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1e9;
const ll MOD = 1e9 + 7;

vector<vector<int> > G;
vector<bool> P;
int ans = 0;
int N, M;

void search(int p, int cnt) {
  if (cnt == N) {
    ans++;
  }

  P[p] = true;
  for (int i = 0; i < G[p].size(); i++) {
    if (!P[G[p][i]]) {
      search(G[p][i], cnt + 1);
    }
  }

  P[p] = false;
}

int main() {
  cin >> N >> M;
  G.resize(N);
  P.resize(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  search(0, 1);

  cout << ans << endl;
  return 0;
}