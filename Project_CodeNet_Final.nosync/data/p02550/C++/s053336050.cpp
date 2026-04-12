#include <iostream>
using namespace std;
using ll = long long;

int a[100005], last[100005];
ll s[100005];

int main() {
  ll n;
  int M;
  cin >> n >> a[1] >> M;
  last[a[1]] = 1;
  s[1] = a[1];
  int R, p;
  ll S;
  for (int i = 2; ; ++i) {
    a[i] = 1LL * a[i - 1] * a[i - 1] % M;
    if (last[a[i]]) {
      R = i - last[a[i]];
      s[i] = s[i - 1] + a[i];
      S = s[i] - s[last[a[i]]];
      p = last[a[i]];
      break;
    }
    last[a[i]] = i;
    s[i] = s[i - 1] + a[i];
  }
  cout << s[p + (n - p) % R] + ((n - p) / R) * S;
  return 0;
}