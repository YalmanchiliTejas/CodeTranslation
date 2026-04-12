#include<iostream>
#include<vector>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N, M; std::cin >> N >> M;
  std::vector<std::vector<int>>G(N);
  for(int i = 0; i < M; ++i) {
    int a, b; std::cin >> a >> b; --a; --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int mask = (1<<N)-1;
  auto dfs = [&](auto&& f, int v, int s) {
    if(s == mask) return 1;
    int res = 0;
    for(int c: G[v]) if(((1<<c)&s)==0) {
      res += f(f, c, s+(1<<c));
    }
    return res;
  };
  fin(dfs(dfs, 0, 1));
  return 0;
}
