#include <iostream>
#include <vector>
#include <string>

typedef long long ll;

int main()
{
  ll H, W;
  std::cin >> H >> W;

  std::string str(W, 'X');
  std::vector< std::string > vs(H, str);

  ll cnt = 0;
  for (ll y = 0; y < H; y++) {
    std::string base(W, '.');
    std::string in;
    std::cin >> in;
    if (in != base) {
      vs[cnt] = in;
      cnt++;
    }
  }

  H = cnt;

  std::vector< std::string > vans(H, str);
  cnt = 0;
  for (ll x = 0; x < W; x++) {
    bool judge = true;
    for (ll y = 0; y < H; y++) {
      if (vs[y][x] != '.') {
	judge = false;
      }
    }
    if (!judge) {
      for (ll y = 0; y < H; y++) {
	vans[y][cnt] = vs[y][x];
      }
      cnt++;
    }
  }

  W = cnt;

  for (ll y = 0; y < H; y++) {
    for (ll x = 0; x < W; x++) {
      std::cout << vans[y][x];
    }
    std::cout << std::endl;
  }

  return 0;
}
