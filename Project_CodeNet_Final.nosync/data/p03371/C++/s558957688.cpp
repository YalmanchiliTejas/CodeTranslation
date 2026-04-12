#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, n) for(int i = 1; i <= (int)(n); i++)
#define rrep(i, n) for(int i = ((int)(n)-1); i >= 0; i--)
#define srep(i, from, to) for(int i = from; i < (int)(to); i++)
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  ll ans = INF;
  rep(i, max(x, y) * 2 + 1) {
    ll now = i * c;
    if(i / 2 < x) now += (x - i / 2) * a;
    if(i / 2 < y) now += (y - i / 2) * b;
    ans = min(ans, now);
  }
  cout << ans << endl;

  return 0;
}
