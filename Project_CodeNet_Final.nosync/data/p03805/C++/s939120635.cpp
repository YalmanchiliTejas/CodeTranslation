#include <bits/stdc++.h>
using namespace std;
int64_t ans = 0, all = 0b00000000;
vector<vector<int64_t>> Graph(8);

void dfs(int node, int bit)
{
  if (bit & (1 << node))
    return;
  bit |= (1 << node);
  if (bit == all)
  {
    ans++;
    return;
  }
  int nextBit = bit;
  for (int i = 0; i < Graph.at(node).size(); i++)
  {
    int nextNode = Graph.at(node).at(i);
    dfs(nextNode, nextBit);
  }
}

int main()
{
  int64_t N, M, a, b;
  cin >> N >> M;
  for (int i = 0; i < M; i++)
  {
    cin >> a >> b;
    a--;
    b--;
    Graph.at(a).push_back(b);
    Graph.at(b).push_back(a);
  }
  for (int i = 0; i < N; i++)
  {
    all |= (1 << i);
  }
  dfs(0, 0b00000000);
  cout << ans << endl;
}
