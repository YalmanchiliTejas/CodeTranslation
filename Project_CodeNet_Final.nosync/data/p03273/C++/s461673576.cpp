#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair< ll, ll > pll;
typedef pair< int, int > pii;

const double pi = 3.14159265358979323846;

#define MOD 1000000007LL
#define PS(p) cout << setprecision(15) << fixed << p << endl;
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
#define ALL(c) c.begin(), c.end()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define MT make_tuple
#define TG0 get< 0 >
#define TG1 get< 1 >
#define TG2 get< 2 >
#define F first
#define S second
#define VL vector< ll >

// to_string(123)
// atoi("123"); atoi(s.c_str());
// "abc".size()
// s.find('+') == string::npos
bool skipW[100];

// -----------------------------------------------------------------------------
// main
// -----------------------------------------------------------------------------
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll H, W;
  cin >> H >> W;

  string hw[H];
  for (ll h = 0; h < H; h++) {
    cin >> hw[h];
  }

  for (ll w = 0; w < W; w++) {
    bool allWhite = true;
    for (ll h = 0; h < H; h++) {
      if (hw[h][w] == '#') {
        allWhite = false;
        break;
      }
    }

    if (allWhite) {
      skipW[w] = true;
    }
  }

  for (ll h = 0; h < H; h++) {
    if (hw[h] == string(W, '.')) {
      // nothing
    } else {
      for (ll w = 0; w < W; w++) {
        if (!skipW[w]) {
          cout << hw[h][w];
        }
      }
      cout << endl;
    }
  }

  return 0;
}
