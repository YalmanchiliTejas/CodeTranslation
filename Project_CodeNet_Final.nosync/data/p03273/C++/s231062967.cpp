#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll H, W; cin >> H >> W;
  char c[H][W];
  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) {
      cin >> c[i][j];
    }
  }
  ll h0[H], w0[W];
  fill(h0,h0+H,0);
  fill(w0,w0+W,0);
  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) {
      if (c[i][j] == '#') h0[i] = 1;
    }
  }
  for (ll j = 0; j < W; j++) {
    for (ll i = 0; i < H; i++) {
      if (c[i][j] == '#') w0[j] = 1;
    }
  }
  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) {
      if (h0[i] == 1 && w0[j] == 1) {cout << c[i][j];}
    }
    if (h0[i] == 1) {cout << endl;}
  }
}