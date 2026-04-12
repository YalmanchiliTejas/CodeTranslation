#include <bits/stdc++.h>

#define pii pair<int, int>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define vec vector<int>
#define dead not_bad
#define bad gooood

#define left not_right
#define y1 what

using namespace std;

const int N = (int) 2e5 + 10;
const int M = (int) 20;
const ll LINF = (ll) 1e18;
const int INF = (int) 1e9 + 7;
const int ALPHA = 26;
const int mod = INF + 2;
const double PI = 3.14159265359;
const ld EPS = (ld) 1e-12;

const int nx[4] = {0, 0, -1, 1};
const int ny[4] = {1, -1, 0, 0};

int n;
pii a[N];
int ans[N];

int main() {
  #define fn "saddle"
  #ifdef witch
      freopen("input.txt", "r", stdin);
  //    freopen("output.txt", "w", stdout);
  #else
      //freopen(fn".in", "r", stdin);
      //freopen(fn".out", "w", stdout);
  #endif
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].f;
    a[i].s = i;
  }
  sort (a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    if (i - 1 >= n / 2) {
        ans[a[i].s] = a[n / 2].f;
    } else  {
        ans[a[i].s] = a[n / 2 + 1].f;
    }
  }
  for (int i = 1; i <= n; i++)
    cout << ans[i] << '\n';
  return 0;
}
