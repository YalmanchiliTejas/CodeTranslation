#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <vector>

int N, M; // N vertices, M edges
const int N_MAX = 8;

std::vector<int> G[N_MAX+1];

int dfs(const int pos, std::array<bool, N_MAX+1> visited);

int main()
{
  std::cin >> N >> M;
  for (int i=0; i<M; i++) {
    int s, t;
    std::cin >> s >> t;
    G[s].push_back(t);
    G[t].push_back(s);
  }

  std::array<bool, N_MAX+1> arr= {};
/*
  for (auto itr=empty.begin(); itr!=empty.end(); itr++) {
    std::cout << *itr << ' ';
  }
  std::cout << std::endl;
*/

  arr[1] = true;
  std::cout << dfs(1, arr);

  return 0;
}

int dfs(const int pos, std::array<bool, N_MAX+1> visited)
{
/*
  for (auto itr=visited.begin(); itr!=visited.end(); itr++) {
    std::cout << *itr << ' ';
  }
  std::cout << '\n';
*/

  bool done = true;
  for (int i=1; i<=N; i++) {
    if (!visited[i]) done = false;
  }
  if (done) {
    //std::cout << "done.\n";
    /*
    for (auto itr=visited.begin(); itr!=visited.end(); itr++) {
      std::cout << *itr << ' ';
    }
    std::cout << '\n';
    */
    return 1;
  }

  int ret = 0;
  for (auto itr=G[pos].begin(); itr!=G[pos].end(); itr++) {
    if (!visited[*itr]) {
      visited[*itr] = true;
      ret += dfs(*itr, visited);
      visited[*itr] = false;
    }
  }

  return ret;
}
