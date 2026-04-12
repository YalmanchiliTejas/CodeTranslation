#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

typedef long long ll;
const ll INF = (ll)1e18 + 1;
const ll MOD = 1e9 + 7;

void print(){ std::cout << std::endl; }
template <typename H> void print(H head) { std::cout << head << std::endl; }
template <typename H, typename... T> void print(H head, T... tail){ std::cout << head << " ", print(tail...); }

ll H, W, V;

int main()
{
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  std::cin >> H >> W;
  std::vector< std::string > grid(H, std::string(W, 'x'));
  for (ll y = 0; y < H; y++) {
    std::cin >> grid[y];
  }

  std::vector< std::string > grid1;
  std::string check(W, '.');
  for (ll y = 0; y < H; y++) {
    if (grid[y] != check) grid1.push_back(grid[y]);
  }

  ll H1 = (ll)grid1.size();
  std::vector< std::string > grid2(H1);
  for (ll x = 0; x < W; x++) {
    bool judge = false;
    for (ll y = 0; y < H1; y++) {
      if (grid1[y][x] == '#') judge = true;
    }
    if (judge == true) {
      for (ll y = 0; y < H1; y++) {
	grid2[y].push_back(grid1[y][x]);
      }
    }
  }

  for (ll y = 0; y < H1; y++) {
    print(grid2[y]);
  }
  return 0;
}
