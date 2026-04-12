/*
 * Author : Andrew J
*/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define vz(x) x.size()
using ll = long long;
using ii = pair <ll , ll>;
void in(ll &x);
// const ll N = ;
const ll INF = 1e9 + 50;
const ll MOD = 1e9 + 7;
ll n, x, m;

ll mul(ll a , ll b) {
  return ((a % m) * (b % m)) % m;
}

ll rsum(int l , int r , vector <ll> &ps) {
  if (l > r) return 0;
  return ps[r] - ps[l - 1];
}

int main() {
  in(n); in(x); in(m);
  ll lst = x;
  vector <ll> ps;
  map <ll , ll> pos;
  pos[x] = 1;
  ps.pb(0); ps.pb(x);
  ll ans = x;
  for (ll i = 2 ; i <= n ; i++) {
    ll cur = mul(lst , lst);
    if (pos.count(cur)) {
      // printf(" hoho %lld -> %lld\n" , pos[cur] , i);
      ps.pb(ps.back() + cur);
      ll len = i - pos[cur];
      ll left = n - i;
      ll whole = rsum(pos[cur] + 1 , i , ps);
      ll rem = rsum(pos[cur] + 1 , pos[cur] + (left % len) , ps);
      // printf(" :: %lld %lld\n" , left , len);
      // printf(" >> %lld %lld\n" , pos[cur] + 1 , i);
      // printf(" >> %lld %lld\n" , pos[cur] + 1 , pos[cur] + (left % len));
      ans += whole * (left / len) + rem + cur;
      break;
    } else {
      pos[cur] = i;
    }
    ans += cur;
    ps.pb(ps.back() + cur);
    // printf("%d -> %lld\n" , i , ps[i]);
    lst = cur;
  }
  printf("%lld\n" , ans);
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
