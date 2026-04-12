//bayemirov
#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

#define pb push_back

const int MOD = 1e9 + 7;

void dec(ll& x, ll y) {
	x -= y;
	if (x < 0)
		x += MOD;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
   int n;
   cin >> n;
   ll sum = 0;
   ll a[n + 1];
   for (int i = 1; i <= n; i++) {
   	cin >> a[i];
   	sum += a[i];
   }
   sum %= MOD;
   ll res = 0;
   for (int i = 1; i <= n; i++) {
   	dec(sum, a[i]);
   	res += (sum * a[i]) % MOD;
   	res %= MOD;
   }
   cout << res;
   return 0;
}