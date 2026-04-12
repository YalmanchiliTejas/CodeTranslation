#include <bits/stdc++.h>
#define FOR(i, m, n) for (int i = m; i < (n); i++)
#define FORR(i, m, n) for (int i = (m); i > 0; i--)
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define MOD = 1000000007
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  cout << n * 800 - (200 * (n / 15)) << endl;
  return 0;
}