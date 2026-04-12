#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
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

ll d(ll n) { return pow(2, n + 2) - 3; }

ll p(ll n, ll x) {
  if(mp.count({n, x})) return mp[{n, x}];
  if(n == 0) return 1;
  if(x <= 1) return 0;
  ll d1 = d(n - 1);
  ll res = 0;
  x--;
  if(x > d1) {
    res += pow(2, n) - 1;
    x -= d1;
  } else {
    mp[{n, x}] = p(n - 1, x);
    return mp[{n, x}];
  }
  res++;
  x--;
  if(x) {
    if(x >= d1)
      res += pow(2, n) - 1;
    else
      res += p(n - 1, x);
  }
  mp[{n, x}] = res;
  return res;
}

int main() {
  ll n, x;
  cin >> n >> x;
  cout << p(n, x) << endl;
}