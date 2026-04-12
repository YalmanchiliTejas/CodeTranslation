#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <bitset>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <climits>
#include <cmath>
#include <stack>
#include <queue>
#include <cfloat>
#include <initializer_list>
#include <iomanip>
#include <functional>
#include <unordered_map>
#include <regex>

using namespace std;

int N, M;
vector<int> adj[20];
bool visited[20];

int bfs(int v, int n)
{
  if (n == N) return 1;
  int res = 0;
  for (int nxt : adj[v])
    {
      if (!visited[nxt])
        {
          visited[nxt] = true;
          res += bfs(nxt, n + 1);
          visited[nxt] = false;
        }
    }
  return res;
}


int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin >> N >> M;
  for (int i = 0; i < M; ++i)
    {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
  visited[1] = true;
  cout << bfs(1, 1) << endl;
  return 0;
}
