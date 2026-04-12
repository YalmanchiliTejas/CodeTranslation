#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
  ll n;
  ll sum = 0;
  ll sum2 = 0;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());
  if (n == 3) {
    sum += abs(a[0]-a[2]);
    sum += max(abs(a[1]-a[0]), abs(a[1]-a[2]));
    cout << sum << endl;
    return 0;
  }
  b[n/2] = a[0];
  ll p = 0;
  bool big = true;
  for (int i = 0; i < n/2; i++) {
    if (big) {
      b[n/2-(i + 1)] = a[n-1 -i];
      b[n/2+(i + 1)] = a[n-2 -i];
      big = false;
    }
    else {
      b[n/2-(i + 1)] = a[p+1];
      b[n/2+(i + 1)] = a[p+2];
      p += 2;
      big = true;
    }
  }
  for (int i = 0; i < n-1; i++) {
    sum += abs(b[i] - b[i+1]);
  }
  

  b[n/2] = a[n-1];
  p = 0;
  big = false;
  for (int i = 0; i < n/2; i++) {
    if (big) {
      b[n/2-(i + 1)] = a[n-1 -i];
      b[n/2+(i + 1)] = a[n-2 -i];
      big = false;
    }
    else {
      b[n/2-(i + 1)] = a[p];
      b[n/2+(i + 1)] = a[p+1];
      p += 2;
      big = true;
    }
  }
  for (int i = 0; i < n-1; i++) {
    sum2 += abs(b[i] - b[i+1]);
  }

  cout << max(sum, sum2) << endl;
  return 0;
}
