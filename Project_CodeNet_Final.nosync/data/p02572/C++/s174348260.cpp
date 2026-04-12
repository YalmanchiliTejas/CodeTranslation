#include <bits/stdc++.h>
using namespace std;

long long a[200005], pref[200005], res = 0;
int main() {
   int n, mod = 1000000007;
   cin >> n;
   for (int i = 1; i <= n; i++) {
       cin >> a[i];
       pref[i] = a[i]+pref[i-1];
   }
   for (int i = 1; i <= n; i++) {
       res += ((pref[i-1]%mod)*(a[i]%mod))%mod;
   }
   cout << res%mod;
}