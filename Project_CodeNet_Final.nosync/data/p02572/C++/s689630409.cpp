#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1000000007

#define SWAP(a,b) ((a != b)? (a += b,b = a - b,a -= b) : 0 ) //数値のみ
#define SWAPs(type,a,b) { type temp = a; a = b; b = temp; } //型指定する ポインタ, 構造体等
#define rng(i, a, b) for(int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define pb push_back
#define eb emplace_back
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed

int main() {
  ll n, m, ans = 0, sum = 0;
  //map<string, int> m;
  //string s, t;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  rep(i, n - 1) {
    sum += a.at(i);
    sum %= MOD;
    ans += (a.at(i + 1) * sum % MOD);
    ans %= MOD;
  } 
  cout << ans << endl;
}
