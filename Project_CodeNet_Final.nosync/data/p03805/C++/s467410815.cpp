#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int N, M;
vector<vector<int>> G;
int ans = 0;

void dfs(int now, int result) {
  int flag = false;
    result |= (1 << now);
    for (auto e : G[now]) {
      if(!(result&(1<<e))){
        dfs(e, result);
        flag = true;
      }
    }
    if(!flag && bitset<8>(result).count() == N){
      ans += 1;
    }
}

int main() {
    cin >> N >> M;
    G.resize(N);

    rep(i, M) {
        int from, to;
        cin >> from >> to;
        from--;
        to--;

        G[from].push_back(to);
        G[to].push_back(from);
    }

    dfs(0, 0);
    cout << ans << endl;
}