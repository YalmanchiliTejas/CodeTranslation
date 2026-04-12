#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
const ll mod = 1e9 + 7;

void solve() {
   int n;
   cin >> n;
   vector <ll> a(n + 1), cm(n + 1);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   for (int i = n - 1; i >= 0; i--) {
      cm[i] = (cm[i + 1] + a[i]) % mod;
   }
   ll ans = 0;
   for (int i = 0; i < n; i++) {
      ans = (ans + (a[i] * cm[i + 1]) % mod) % mod;
   }
   cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("inp.txt", "r", stdin);      freopen("outp.txt", "w", stdout);
#endif
   ios::sync_with_stdio(false);   cin.tie(NULL);   cout.tie(NULL);

   solve();

   return 0;
}