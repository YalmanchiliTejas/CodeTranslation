#include <bits/stdc++.h>
#define INF 100000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll H, W;
  cin >> H >> W;
  vector<vector<char>> maze(H, vector<char>(W));
  for (ll i = 0; i < H; ++i) {
    for (ll j = 0; j < W; ++j) {
      cin >> maze.at(i).at(j);
    }
  }
  vector<bool> h_del(H, false);
  vector<bool> w_del(W, false);
  for (ll i = 0; i < W; ++i) {
    bool all = true;
    for (ll j = 0; j < H; ++j) {
      if (maze.at(j).at(i) != '.') {
        all = false;
        break;
      }
    }
    if (all) {
      w_del.at(i) = true;
    }
  }
  for (ll i = 0; i < H; ++i) {
    bool all = true;
    for (ll j = 0; j < W; ++j) {
      if ('.' != maze.at(i).at(j)) {
        all = false;
        break;
      }
    }
    if (all) {
      h_del.at(i) = true;
    }
  }
  for (ll i = 0; i < H; ++i) {
    bool no = true;
    for (ll j = 0; j < W; ++j) {
      if (h_del.at(i) || w_del.at(j)) {
        continue;
      }
      cout << maze.at(i).at(j);
      no = false;
    }
    if (!no) {
      cout << endl;
    }
  }
}
