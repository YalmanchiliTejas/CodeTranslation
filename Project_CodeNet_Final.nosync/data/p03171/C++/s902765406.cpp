#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007
#define h1 7897897897897897
#define h2 7897466719774591
#define b1 98762051
#define b2 98765431
#define inf 1000000000
#define pi 3.1415926535897932384626
#define LMAX 9223372036854775807
#define ll long long
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pii>
#define SET(a, b) memset(a, b, sizeof(a));
#define all(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
int n, m, k, t, T, x, y, sum, cnt, ans;
ll a[3005], dp[3005][3005], p[3005];
ll recur(int l, int r) {
  if (l == r) return a[l];
  if (dp[l][r]) return dp[l][r];
  ll one = p[r] - p[l] - recur(l + 1, r) + a[l];
  ll two = p[r-1] - p[l-1] - recur(l, r - 1) + a[r];
  return dp[l][r] = max(one, two); 
}
int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  FOR(i, 1, n) {
    cin >> a[i];
    p[i] = p[i-1] + a[i];
  }
  ll A = recur(1, n);
  cout << A + A - p[n] << endl;
  return 0;
}
