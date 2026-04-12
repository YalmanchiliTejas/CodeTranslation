#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

#include <algorithm>
#include <functional>
#include <iterator>
#include <map>
#include <set>
#include <string>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n)-1; i >= 0; i--)
#define INF 1 << 29
#define ALEN(ARR) (sizeof(ARR) / sizeof((ARR)[0]))
#define MP make_pair
#define mp make_pair
#define pb push_back
#define PB push_back

#if DEBUG
#define _DEBUG(x) cout << #x << ": " << x << endl
#define _DDEBUG(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl
#else
#define _DEBUG(x) ;
#define _DDEBUG(x, y) ;
#endif

#define ll long long
#define ull unsigned long long
#define MOD 1000000007

/** FOR VECTOR DEBUG */
template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) {
  if (!v.empty()) {
    out << '[';
    copy(v.begin(), v.end(), ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}

/* template end */

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(16);

  int h, w;
  cin >> h >> w;

  string table[h];
  bool check[h][w];
  vector<int> wv(w);
  for (int i = 0; i < h; i++) {
    bool t = true;
    cin >> table[i];
    for (int j = 0; j < w; j++) {
      if (table[i][j] == '#') {
        t = false;
      }
      wv[j] += table[i][j] == '.' ? 1 : 0;
      check[i][j] = true;
    }
    if (t) {
      for (int j = 0; j < w; j++) {
        check[i][j] = false;
      }
    }
  }

  for (int i = 0; i < w; i++) {
    if (wv[i] == h) {
      for (int j = 0; j < h; j++) {
        check[j][i] = false;
      }
    }
  }

#if DEBUG
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << check[i][j] << ' ';
    }
    cout << endl;
  }

  cout << "** RESULT **" << endl; // debug
#endif

  for (int i = 0; i < h; i++) {
    bool f = false;
    for (int j = 0; j < w; j++) {
      if (check[i][j]) {
        cout << table[i][j];
        f = true;
      }
    }
    if (f) {
      cout << endl;
    }
  }

  return 0;
}
