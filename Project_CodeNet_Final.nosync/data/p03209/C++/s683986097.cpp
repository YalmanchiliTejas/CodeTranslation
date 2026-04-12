#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

map<P, ll> mp;

ll f(ll i, ll x) {
  if(x <= 0 || i < 0) return 0;
  if(i == 0) return 1;
  if(mp.count({i, x})) return mp[{i, x}];
  ll a = (1LL << (i + 1)) - 3;
  ll res;
  if(x == 1)
    res = 0;
  else if(x < a + 2)
    res = f(i - 1, x - 1);
  else
    res = f(i - 1, a) + f(i - 1, x - a - 2) + 1;
  mp[{i, x}] = res;
  return res;
}

int main() {
  ll n, x;
  cin >> n >> x;
  cout << f(n, x) << endl;
}