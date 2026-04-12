#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const double pi = 3.14159265358979323846;

#define REP(i, n) for (ll i = 0; i < n; i++)
#define MOD 1000000007LL
#define PS(p) cout << setprecision(15) << fixed << p << endl;
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
#define ALL(c) c.begin(), c.end()
#define CIN(v) cin >> v;
#define COUT(v) cout << v << "\n";

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int X;
  CIN(X);
  bool happy = false;
  if (X == 3)
    happy = true;
  if (X == 5)
    happy = true;
  if (X == 7)
    happy = true;

  if (happy) {
    COUT("YES");
  } else {
    COUT("NO");
  }

  return 0;
}
