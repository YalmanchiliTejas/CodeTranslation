#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <utility>
#include <chrono>
#include <sstream>
#include <iomanip>

#define INF 1 << 30
#define MOD 1000000007;
#define PI 3.14159265358979
#define rep(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)
#define reu(i, l, r) for (int (i) = (int)(l); (i) < (int)(r); (i)++)
#define D(x) cout << x << endl
#define d(x) cout << x
#define all(x) (x).begin(), (x).end()
#define pub(x) push_back(x)
#define pob() pop_back()
#define puf(x) push_front(x)
#define pof() pop_front()
#define mp(x, y) make_pair((x), (y))
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
template<typename T, typename U> inline void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if (x < y) x = y; }

static const int dx[] = {0, 0, 1, -1};
static const int dy[] = {-1, 1, 0, 0};

int main() { 
  int n;
  cin >> n;
  string s;
  int cnt[55][128];
  rep (i, 55) rep (j, 128) cnt[i][j] = 0;
  rep (i, n) {
    cin >> s;
    rep (j, s.size()) {
      cnt[i][s[j]]++;
    }
  }

  int mins[128];
  rep (i, 128) mins[i] = INF;

  rep (i, 128) {
    rep (j, n) {
      amin(mins[i], cnt[j][i]);
    }
  }

  //rep (i, 128) {
  //  D(mins[i]);
  //}

  
  rep (i, 128) {
    rep (j, mins[i]) {
      char a;
      a = i;
      d(a);
    }
  }
  D("");

  return 0;
}

