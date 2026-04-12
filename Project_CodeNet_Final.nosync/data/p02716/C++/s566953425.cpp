/*
 * Author : Andrew J
*/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
using ll = long long;
typedef pair <ll , ll> ii;
void in(ll &x);
const ll N = 2e5 + 10;
const ll inf = 1e16;
ll n;
ll a[N],dp1[N][2],dp2[N][2];

ll fltor(ll cur , bool lr) {
   // lr = 0, terakhir ambil kiri otherwise kanan
   if (cur > n) return 0;
   ll &sol = dp1[cur][lr];
   if (sol != -1) return sol;
   if (lr) {
      sol = fltor(cur + 2 , 1) + a[cur + 1];
   } else {
      sol = max(fltor(cur + 2 , 0) + a[cur] , fltor(cur + 2 , 1) + a[cur + 1]);
   }
   return sol;
}

ll frtol(ll cur , bool lr) {
   // lr = 0, trakhir ambil kiri
   // lr = 1, trakhir ambil kanan
   if (cur <= 0) return 0;
   ll &sol = dp2[cur][lr];
   if (sol != -1) return sol;
   if (lr) {
      sol = max(frtol(cur - 2 , 0) + a[cur - 1] , frtol(cur - 2 , 1) + a[cur]);
   } else {
      sol = frtol(cur - 2 , 0) + a[cur - 1];
   }
   return sol;
}

int main() {
   memset (dp1 , -1 , sizeof dp1);
   memset (dp2 , -1 , sizeof dp2);
   in(n);
   for (ll i = 1 ; i <= n ; i++) {
      in(a[i]);
   }
   if (n & 1) {
      ll sol = LLONG_MIN;
      for (ll i = 1 ; i <= n ; i += 2) {
         ll cur = fltor(i + 1 , 0);
         cur += frtol(i - 1 , 1);
         sol = max(sol , cur);
      }
      printf("%lld\n" , sol);
   } else {
      printf("%lld\n" , fltor(1 , 0));
   }
   return 0;
}

void in(ll &x) {
	bool neg = false;
	register ll c;
	x = 0;
	c = getchar();
	if(c == '-') {
		neg = true;
		c = getchar();
	}
	for (; c > 47 && c < 58; c = getchar())
   	x = (x << 1) + (x << 3) + c - 48;
	if (neg) x *= -1;
}
