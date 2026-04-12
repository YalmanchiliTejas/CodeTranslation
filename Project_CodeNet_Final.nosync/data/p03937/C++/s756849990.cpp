#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

using ll = long long;
const ll INF = (ll)1e18;

ll H, W;

int main(int argc, char* argv[])
{
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  std::cin >> H >> W;
  std::vector< std::string > vs(H, std::string(W, '.'));
  std::vector< std::vector<ll> > dist(H, std::vector<ll>(W, INF));

  ll sharp_cnt = 0;
  for (ll y = 0; y < H; y++) {
    for (ll x = 0; x < W; x++) {
      std::cin >> vs[y][x];
      if (vs[y][x] == '#') {
	sharp_cnt++;
      }
    }
  }

  // y, x
  std::queue< std::pair< ll, ll > > que;

  dist[0][0] = 1;
  que.push(std::make_pair(0, 0));

  while (!que.empty()) {
    std::pair< ll, ll > p = que.front();
    que.pop();
    ll y = p.first;
    ll x = p.second;
    if (x+1 < W && y < H && vs[y][x+1] == '#') {
      if (dist[y][x+1] > dist[y][x] + 1) {
	dist[y][x+1] = dist[y][x] + 1;
	que.push(std::make_pair(y, x+1));
      }
    }
    if (x < W && y+1 < H && vs[y+1][x] == '#') {
      if (dist[y+1][x] > dist[y][x] + 1) {
	dist[y+1][x] = dist[y][x] + 1;
	que.push(std::make_pair(y+1, x));
      }
    }
  }


  if (dist[H-1][W-1] == sharp_cnt) {
    std::cout << "Possible" << std::endl;
  } else {
    std::cout << "Impossible" << std::endl;
  }
  return 0;
}
