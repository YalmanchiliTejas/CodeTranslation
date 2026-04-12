#include <bits/stdc++.h>

using namespace std;

int mod = 998244353;

int add() { return 0; }
template<typename... M> int add(int a, M... b) {
  int x = add(b...);
  return a + x - mod * (a + x >= mod);
}

int mul() { return 1; }
template<typename... M> int mul(int a, M... b) {
  return int(1ll * a * mul(b...) % mod);
}

int pwr(int a, long long x) {
  return (x ? mul(pwr(mul(a, a), x >> 1), (x & 1 ? a : 1)) : 1);
}

int dvd(int a, int b) {
  return mul(a, pwr(b, mod - 2));
}

int sub(int a, int b) {
  return a - b + mod * (a < b);
}

void inc(int& a, int b) {
  a = add(a, b);
}

void dec(int& a, int b) {
  a = sub(a, b);
}

vector<int> fact = {1}, invf = {1};
int C(int n, int k) {
  if (n < k or 0 > k) return 0;
  while (fact.size() <= n) {
    fact.push_back(mul(fact.back(), fact.size()));
    invf.push_back(dvd(1, fact.back()));
  }
  return mul(fact[n], invf[k], invf[n - k]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  long long n;
  int x;
  cin >> n >> x >> mod;
  long long ans = 0;
  int cnt = 0;
  vector<long long> pr = {0};
  vector<int> used(mod, -1);
  while (cnt < n and used[x] == -1) {
    used[x] = cnt++;
    pr.push_back(pr.back() + x);
    x = mul(x, x);
  }
  if (cnt == n) cout << pr.back();
  else cout << pr[used[x]] + (pr[cnt] - pr[used[x]]) * ((n - used[x]) / (cnt - used[x])) + pr[used[x] + ((n - used[x]) % (cnt - used[x]))] - pr[used[x]];

  return 0;
}
