#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> G[100];
bool visited[100];

int dfs(int from, int cnt) {
   if (cnt >= N-1) {
      return 1;
   }

   visited[from] = true;
   int ret = 0;
   for (int to : G[from]) {
      if (visited[to]) continue;
      ret += dfs(to, cnt+1);
   }
   visited[from] = false;

   return ret;
}

int main() {
   cin >> N >> M;
   for (int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      G[a].push_back(b);
      G[b].push_back(a);
   }

   cout << dfs(0, 0) << endl;

   return 0;
}