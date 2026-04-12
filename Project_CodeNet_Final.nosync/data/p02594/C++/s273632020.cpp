#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#define rep(i, x) for(ll i = 0; i < x; i++)
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
  
  int x; cin >> x;
  if (x >= 30) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}