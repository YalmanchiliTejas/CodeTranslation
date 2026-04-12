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

int N, A, B, C, X;
int next(int x) {
  return x == -1 ? X : (A * x + B) % C;
}

int main() {
  for (; cin >> N >> A >> B >> C >> X, (N|A|B|C|X) != 0; ) {
    int Y[101];
    rep(i, N) cin >> Y[i];

    int ans = -1;
    int x = -1;
    rep(i, N) {
      for (; ans <= 10000; ) {
        x = next(x);
        ans++;
        if (x == Y[i]) break;
      }
    }
    if (ans == 10001) cout << -1 << endl;
    else cout << ans << endl;
  }
  
  return 0;
}