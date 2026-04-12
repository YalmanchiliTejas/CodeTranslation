#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> a;
int n;

bool isok(ll m) {
  ll cnt = 0;
  for (int i = 0; i < n && cnt <= m; i++) {
    ll t = a[i] + m - (n - 1);
    ll d = n+1;
    cnt += (t+d-1) / d;
  }
  return cnt <= m;
}

ll f() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i <= 1e7; i++) {
    if (isok(i)) return i;
  }
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  sum -= n*(n-1);
  for(;;sum++) if (isok(sum)) return sum;
}

int main() {
  cout << f() << endl;
}