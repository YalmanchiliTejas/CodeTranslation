#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <fstream>

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

using namespace std;
typedef long long unsigned int ll;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string>  as;
  string a;
  for (int i = 0; i < H; ++i) {
    cin >> a;
    as.push_back(a);
  }

  vector<bool> col(H, false);
  vector<bool> row(W, false);

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (as[i][j] == '#') {
	col[i] = true;
	row[j] = true;
      }
    }
  }

  for (int i = 0; i < H; ++i) {
    if (col[i]) {
      for (int j = 0; j < W; ++j) {
	if (row[j]) {
	  cout << as[i][j];
	}
      }
      cout << endl;
    }
  }

  return 0;
}
