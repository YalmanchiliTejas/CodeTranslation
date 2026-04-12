//\\//\\ * * * //\\// ||
#include <bits/stdc++.h> 

#define debug(x) cerr << #x << ": " << x << endl

using namespace std;

typedef long long ll;

const int N = (int) 1e5 + 10;

bool mark[N];
ll a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, x, m;
  cin >> n >> x >> m;
  a[0] = x;
  mark[x] = true;
  for (ll i = 1; i <= m; i++) {
    a[i] = (a[i - 1] * a[i - 1]) % m;
    if (mark[a[i]]) {
      ll sum1 = 0, sum2 = 0;
      ll flag = -1;
      for (ll j = 0; j < i; j++) {
        if (a[j] != a[i]) {
          sum1 += a[j];
          continue;
        }
        sum1 += a[j];
        flag = j;
        break;
      }
      for (ll j = flag + 1; j <= i; j++) {
        sum2 += a[j];
      }
      ll len = i - flag;
      ll nn = n - (flag + 1);
      sum1 += (nn / len) * sum2;
      for (ll j = 0; j < nn % len; j++) {
        sum1 += a[j + flag + 1];
      }
      cout << sum1 << '\n';
      return 0;
    } else {
      mark[a[i]] = true;
      continue;
    }
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
      sum += a[i];
    }
    cout << sum << '\n';
  }
  return 0;
}
