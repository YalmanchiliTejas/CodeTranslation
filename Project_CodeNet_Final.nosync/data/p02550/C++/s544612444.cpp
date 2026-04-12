#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

 
string to_string(string s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

ll bigmod(ll a, ll n, ll M) {
  ll res = 1LL;
  while (n) {
    if (n & 1) res = (res * a) % M;
    a = (a * a) % M;
    n >>= 1;
  }
  return res % M;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll n, x, m;
  cin >> n >> x >> m;
  if (x == 0) {
    cout << 0 << '\n';
    return 0;
  }
  ll cur = x; 
  map<ll, int> mp;
  vector<ll> v;
  int ptr = 1;
  v.push_back(cur);
  mp[cur] = ptr++;
  int cnt = 0, st = 1;
  ll ans = cur;
  n--;
  for (int i = 1; ; ++i) {
    if (n == 0) break;
    cur = (cur*cur) % m;
    if (mp[cur]) {
      st = mp[cur];
      break;
    }
    mp[cur] = ptr++;
    v.push_back(cur);
    n--;
    ans += cur;
  }
  int sz = 0;
  ll tot = 0;
  for (int i = st - 1; i < v.size(); ++i) {
    tot += v[i];
    sz++;
  }
  ans += 1LL*(n/sz)*tot;
  ll rem = n % sz;
  for (int i = 0; i < rem; ++i) ans += v[i + st - 1];
  cout << ans << '\n';
}