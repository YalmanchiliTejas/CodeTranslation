#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <functional>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(obj) (obj).begin(), (obj).end()
#define debug(x) cout << #x << ": " << x << endl
const int MOD = 1000000007;
const int INF = 100100100;
const double EPS = 0.000000001;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, h[30];
  cin >> n;
  REP(i, n) {
    cin >> h[i];
  }
  int ans = 0;
  int max = 0;
  REP(i, n) {
    if(h[i] >= max) {
      ans++;
      max = h[i];
    }
  }
  cout << ans << endl;
  return 0;
}
