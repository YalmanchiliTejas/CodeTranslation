#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,j,n) for(int i=j;i<n;++i)
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(), i.rend()
#define INF 1e9
#define LINF 1e18
const int mod = 1e9 + 7;
 
typedef long long i64;
typedef pair<int, int> pi;
 
template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;
 
i64 gcd(i64 n, i64 m) {return (m == 0? n : gcd(m, n % m));}
i64 lcm(i64 n, i64 m) {return (n / gcd(n, m) * m);}
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

const int sz = 300;

i64 fac[sz], finv[sz], inv[sz];

void init() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;

  for(i64 i = 2; i < sz; ++i) {
    fac[i] = fac[i - 1] * i % mod;
    inv[i] = mod - inv[mod % i] * (mod / i) % mod;
    finv[i] = finv[i - 1] * inv[i] % mod;
  }
}

i64 get(int n, int k) {
  return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  int k;
  cin >> s >> k;

  if(k == 2 && s.size() < 2) return cout << 0 << endl, 0;
  if(k == 3 && s.size() < 3) return cout << 0 << endl, 0;

  init();

  i64 ans = 0;
  int n = s.size();
  rep(i, k, n) {
    if(k == 1) ans += 9;
    else if(k == 2) ans += 9 *  9 * (i - 1);
    else if(k == 3) ans += 9 * 9 *  9 * get(i - 1, 2);
  }

  int num = s[0] - '0';
  if(k == 1) {
    ans += num;
  }
  else if(k == 2) {
    ans += (num - 1) * 9 * (n - 1);
    int i = 1;
    while(i < n && s[i] == '0') ++i;
    if(i < n) ans += s[i] - '0';
    if(i + 1 < n) ans += 9 * (n - i - 1);
  }
  else if(k == 3) {
    ans += (num - 1) * 9 * 9 * get(n - 1, 2);
    int i = 1;
    while(i < n && s[i] == '0') ++i;
    if(i + 1 < n) ans += ((s[i] - '0') - 1) * 9 * (n - i - 1);
    int j = i + 1;
    while(j < n && s[j] == '0') ++j;
    if(j < n) ans += s[j] - '0';
    if(j + 1 < n) ans += 9 * (n - j - 1);
    if(n - i - 1 >= 2) ans += 9 * 9 * get(n - i - 1, 2);
  }
  cout << ans << endl;
}