#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, n) FOR(i, 0, n)
#define ll long long
#define pdd pair <double, double>
#define X first
#define Y second

using namespace std;

const int OFF = (1 << 18);
ll tour[2 * OFF], prop[2 * OFF];
vector <pair <int, ll> > ve[OFF];

void update(int a, int b, ll v, int lo = 0, int hi = OFF, int x = 1) {
  if (b <= lo || hi <= a) return;
  if (a <= lo && hi <= b) {
    tour[x] += v;
    prop[x] += v;    
    return;
  }

  int mi = (lo + hi) / 2;
  update(a, b, v, lo, mi, x * 2);
  update(a, b, v, mi, hi, x * 2 + 1);
  tour[x] = max(tour[x * 2], tour[x * 2 + 1]) + prop[x];

  return;
}

int main() {
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  REP(i, m) {
    int a, b; ll c;
    cin >> a >> b >> c;
    ve[b - 1].push_back({a - 1, c});
  }

  REP(i, n) {
    update(i, i + 1, tour[1]);

    for (auto tr : ve[i]) {
      update(tr.first, i + 1, tr.second);
    }
  }

  cout << tour[1] << "\n";

  return 0;
}