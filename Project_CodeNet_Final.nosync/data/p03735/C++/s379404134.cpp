#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define MP(a, b) make_pair(a, b)

const int MAX_VALUE = 1e9+1;
const int MIN_VALUE = 0;

int N;
vii balls;

ll min (ll a, ll b) {
  if (a > b) return b;
  return a;
}

ll max (ll a, ll b) {
  if (a < b) return b;
  return a;
}

int main() {

  cin >> N;
  REP(i, N) {
    int x, y;
    cin >> x >> y;
    balls.push_back(MP(min(x, y), max(x, y)));
  }
  sort(balls.begin(), balls.end());

  ////////////////////////////
  // Rmax = MAX, Bmin = MIN //
  ////////////////////////////
  int Rmin, Rmax, Bmin, Bmax;
  Rmin = Bmin = MAX_VALUE;
  Rmax = Bmax = MIN_VALUE;

  REP (i, N) {
    Rmin = min(Rmin, balls[i].second);
    Bmin = min(Bmin, balls[i].first);
    Rmax = max(Rmax, balls[i].second);
    Bmax = max(Bmax, balls[i].first);
  }
  ll ans = 1l * (Rmax - Rmin) * (Bmax - Bmin);

  ////////////////////////////
  // Rmax = MAX, Rmin = MIN //
  ////////////////////////////
  ll Rdiff = Rmax - Bmin;
  int minF, minS, maxF, maxS;
  minF = balls[1].first;
  maxF = balls[N-1].first;
  minS = maxS = balls[0].second;

  REP (i, N-1) {
    minF = balls[i+1].first;
    minS = min(minS, balls[i].second);
    maxS = max(maxS, balls[i].second);
    int temp = max(maxF, maxS) - min(minF, minS);
    ans = min(ans, Rdiff * temp);
  }

  cout << ans << endl;

}