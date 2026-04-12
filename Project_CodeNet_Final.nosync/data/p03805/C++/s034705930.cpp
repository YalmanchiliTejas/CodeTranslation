#include <bits/stdc++.h>
using namespace std;

bool is_valid_route(vector<int> &route, vector<vector<bool>> &edges)
{
  for (int i = 0; i < route.size() - 1; i++)
  {
    int from = route.at(i);
    int to = route.at(i + 1);
    if (!edges.at(from).at(to))
    {
      return false;
    }
  }
  return true;
}

int main()
{
  int n_vertex, n_edge;
  cin >> n_vertex >> n_edge;

  vector<int> route(n_vertex);
  vector<vector<bool>> edges(n_vertex, vector<bool>(n_vertex));
  for (int i = 0; i < n_edge; i++)
  {
    int a, b;
    cin >> a >> b;
    edges.at(a - 1).at(b - 1) = true;
    edges.at(b - 1).at(a - 1) = true;
  }

  for (int i = 0; i < n_vertex; i++)
  {
    route.at(i) = i;
  }

  int ans = 0;
  do
  {
    if (route.at(0) != 0)
    {
      break;
    }
    if (is_valid_route(route, edges))
    {
      ans++;
    }
  }
  while (next_permutation(route.begin(), route.end()));
  cout << ans << endl;
}
