#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str;
 
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
 
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define endl '\n'
 
const ll MOD = 1000000007;

int main() {
   int n; scanf("%d", &n);
   vector<ll> a(n);
   for (ll &i : a)
      scanf("%lld", &i);
   ll ans = 0;
   for (ll i : a) {
      ans += i;
      ans = ans % MOD;
   }
   ans *= ans;
   ans = ans % MOD;
   for (ll i : a) {
      ans -= i * i;
      if (ans < 0) {
         ll temp = (-ans + MOD - 1) / MOD;
         ans += temp * MOD;
      }
      ans = ans % MOD;
   }
   ans *= 500000004;
   ans = ans % MOD;
   printf("%lld", ans);
   return 0;
}