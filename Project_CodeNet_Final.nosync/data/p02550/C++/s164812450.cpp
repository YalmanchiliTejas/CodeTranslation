#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#include <set>
#define rep(i, x) for(ll i = 0; i < x; i++)
#define CONCAT_(x,y) x##y
#define CONCAT(x,y) CONCAT_(x,y)
#define _v1 CONCAT(qyw1, __LINE__) // unique name in same line (otherwise use __COUNTER__)
#define _v2 CONCAT(qyw2, __LINE__)
#define forbits(i, m) for (int _v1 = m, i = __builtin_ctz(_v1); _v1 != 0; _v1 ^= _v1 & -_v1, i = __builtin_ctz(_v1))
#define forsubm(s, m) for (int s = m; s >= 0; s = !s ? -1 : m & (s - 1))
int __nextXZW(int v){int t=v|(v-1);int w=(t+1)|(((~t&-~t)-1)>>(__builtin_ctz(v)+1));return w;}
#define ksets(i, n, k) for (int i = (1u << k) - 1, max = i << (n - k); i <= max; i = __nextXZW(i))
using namespace std;
typedef long long ll;
const ll MOD = (ll)1e9+7;
const ll N = 5e5+5, inf = 1e9+5000;
ll add(ll x, ll y) { x += y; if (x >= MOD) return x - MOD; return x; }
ll sub(ll x, ll y) { x -= y; if (x < 0) return x + MOD; return x; }
ll mult(ll x, ll y) { return (x * y) % MOD; }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  ll n, x, m; cin >> n >> x >> m;

  ll ans = x;
  ll curr = x;
  vector<int> seen(100005, -1);
  seen[x] = 0;
  for (int i = 1; i < n; i++) {
    curr = (curr*curr) % m;
    if (seen[curr] != -1) {
      ll start = curr;
      ll loop_size = i-seen[curr];
      ll rest_size = (n - i)%loop_size;
      ll rounds = (n - i)/loop_size;
      
      ll loop = 0;
      ll curr = start;
      for (int j = 0; j < loop_size; j++) {
        loop += curr;
        curr = (curr*curr) % m;
      }

      ans += (loop * rounds);

      ll rest = 0;
      curr = start;
      for (int j = 0; j < rest_size; j++) {
        rest += curr;
        curr = (curr*curr) % m;
      }

      ans += rest;

      break;
    } else seen[curr] = i;

    ans += curr;
  }

  cout << ans << endl;

  return 0;
}