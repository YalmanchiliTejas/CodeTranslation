#include <algorithm>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <stack>
#include <set>
#include <vector>

using namespace std;

#define all(c) ((c).begin()), ((c).end())
#define dump(c) cerr << "> " << #c << " = " << (c) << endl;
#define iter(c) __typeof((c).begin())
#define tr(i, c) for (iter(c) i = (c).begin(); i != (c).end(); i++)
#define REP(i, a, b) for (int i = a; i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define mp make_pair
#define fst first
#define snd second
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int,int> pii;

const int INF = 1 << 29;
const double EPS = 1e-10;


int main() {
  int cases; cin >> cases;

  while (cases--) {
    int M, Y, N; cin >> M >> Y >> N;
    int ans = 0;
    rep(i, N) {
      int T, F;
      double R;
      cin >> T >> R >> F;

      int unyo = M, rishi = 0;
      rep(j, Y) {
        int t = unyo * R;
        if (T) unyo += t;
        else rishi += t;
        unyo -= F;
      }

      ans = max(ans, unyo + rishi);
    }

    cout << ans << endl;
  }
  
  
  return 0;
}