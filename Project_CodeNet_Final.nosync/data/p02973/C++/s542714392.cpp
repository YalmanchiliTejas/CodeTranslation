#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * b / gcd(a, b); }

int main()
{
  int n;
  cin >> n;
  vector<int> v(n);
  REP(i, n) cin >> v[i];
  vector<int> w;
  REP(i, n) {
    int ub = lower_bound(ALL(w), v[i]) - w.begin() - 1;
    if (ub < 0) {
      w.insert(w.begin(), v[i]);
    } else {
      w[ub] = v[i];
    }
  }
  int ans = w.size();
  cout << ans << endl;
  return 0;
}
