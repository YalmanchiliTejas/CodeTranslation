/*
 * Author : Andrew J
*/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
using ll = long long;
using ii = pair <ll , ll>;
void in(ll &x);
const ll N = 1e4 + 10;
const ll M = 1e9 + 7;
char s[N];
ll n, d;
ll dp[N][105][2];

ll ctoi(char x) {
  return x - '0';
}

ll add(ll a , ll b) {
  return ((a % M) + (b % M)) % M;
}

ll subs(ll a , ll b) {
  return (((a % M) - (b % M)) + 2 * M) % M;
}

ll f(ll cur , ll modulo , bool isFree) {
  if (cur >= n) return modulo == 0;
  ll &sol = dp[cur][modulo][isFree];
  if (sol != -1) return sol;
  sol = 0;
  if (!isFree) {
    for (ll i = 0 ; i < ctoi(s[cur]) ; i++) {
      sol = add(sol , f(cur + 1 , (modulo + i) % d , 1));
    }
    sol = add(sol , f(cur + 1 , (modulo + ctoi(s[cur])) % d , 0));
  } else {
    for (ll i = 0 ; i < 10 ; i++) {
      sol = add(sol , f(cur + 1 , (modulo + i) % d , 1));
    }
  }
  return sol;
}

int main() {
  scanf("%s" , s);
  n = strlen(s);
  scanf("%d" , &d);
  memset (dp , -1 , sizeof dp);
  ll sol = 0;
  for (ll i = 0 ; i < ctoi(s[0]) ; i++) {
    sol = add(sol , f(1 , (i % d) , 1));
  }
  sol = add(sol , f(1 , ctoi(s[0]) % d , 0));
  printf("%lld\n" , subs(sol , 1));
  return 0;
}

void in(ll &x){
	bool neg = false;
	register ll c;
	x = 0;
	c = getchar();
	if(c == '-'){
		neg = true;
		c = getchar();
	}
	for (; c > 47 && c < 58; c = getchar())
	x = (x << 1) + (x << 3) + c - 48;
	if (neg) x *= -1;
}
