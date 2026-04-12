#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;
ll m = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
  }
  ll temp = 0;
  for(int i=1; i<n; i++) temp += a[i];
  ll sum = 0;
  rep(i, n-1) {
    sum = (sum % m + ((a[i] % m) * (temp % m)) % m) % m;
    // sum = sum % m + ((a[i] % m) * (temp % m)) % m;
    temp -= a[i+1];
  }
  cout << sum << endl;
  return 0;
}
