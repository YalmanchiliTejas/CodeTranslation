#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()
using namespace std;
using llong = long long;
using P = pair<int, int>;
const int inf = 1 << 20;
const int mod = 1e9 + 7;

bool flag[3005][3005];
llong dp[3005][3005];
int a[3005];
llong f(int l, int r) {
   if (flag[l][r]) return dp[l][r];
   flag[l][r] = true;
   if (l == r) return dp[l][r] = a[l];
   return dp[l][r] = max(a[l] - f(l + 1, r), a[r] - f(l, r - 1));
}
int main() {
   int n;
   cin >> n;
   rep(i, 0, n) cin >> a[i];
   cout << f(0, n - 1) << endl;
   return 0;
}