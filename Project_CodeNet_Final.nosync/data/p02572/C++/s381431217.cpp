////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

namespace my {
/*汎用*/
template <typename T>
void input_vec(vector<T> &a, ll n) {
  if (!a.empty()) {
    cout << "error in input_vec" << endl;
    exit(1);
  }
  for (ll i = 0; i < n; i++) {
    T tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
}
template <typename T>
void input_set(set<T> &a, ll n) {
  if (!a.empty()) {
    cout << "error in input_set" << endl;
    exit(1);
  }
  for (ll i = 0; i < n; i++) {
    T tmp;
    cin >> tmp;
    a.insert(tmp);
  }
}

char itoc(int i) { return i + '0'; }
int ctoi(char c) { return c - '0'; }

/*整数*/
ll gcd(ll a, ll b) {  // O( log(max(a,b)) )
  a = abs(a);
  b = abs(b);
  if (a < b) swap(a, b);
  while (b != 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}
ll lcm(ll a, ll b) { return a * (b / my::gcd(a, b)); }  // O( log(max(a,b)) )
ll modinv(ll n, ll mod) {                               // O( log(max(n,mod)) )
  if (mod < 0 || my::gcd(n, mod) != 1) {
    cout << "error in modinv" << endl;
    exit(1);
  }
  n %= mod;
  if (n < 0) n += mod;
  ll a = mod, b = n, x = 1, y = 0;
  while (b != 0) {
    ll q = a / b, r = a % b;
    a = b;
    b = r;
    y -= q * x;
    swap(x, y);
  }
  y %= mod;
  if (y < 0) y += mod;
  return y;
}

bool isPrime(ll n) {  // O( sqrt(n) )
  bool flag = true;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      flag = false;
      break;
    }
  }
  return flag;
}
vector<pair<ll, ll>> primeFac(ll n) {  // O( sqrt(n) )
  vector<pair<ll, ll>> ret;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i != 0) continue;
    ll exp = 0;
    while (n % i == 0) {
      n /= i;
      exp++;
    }
    ret.push_back(make_pair(i, exp));
  }
  if (n != 1) ret.push_back(make_pair(n, 1));
  return ret;
}
}  // namespace my
////////////////////////////////////////////////

int main() {
  const ll M = 1e9 + 7;
  int n;
  cin >> n;
  vector<ll> a;
  my::input_vec(a, n);

  ll sum = 0;
  for (auto &ai : a) sum += ai;
  ll ans = 0;
  for (auto &ai : a) {
    ans += ai * ((sum - ai) % M);
    ans %= M;
  }
  ans *= my::modinv(2, M);
  ans %= M;
  cout << ans << endl;
}