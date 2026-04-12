#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // freopen("30.txt", "r", stdin);

  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());

  int i = 0, j = 1;
  while (i < n / 2) {
    b[j] = a[i];
    i++;
    j += 2;
  }
  b[0] = a[i];
  i++;
  if (n % 2 != 0) {
    j--;
    b[j] = a[i];
    i++;
    j -= 2;
  } else {
    j -= 3;
  }
  while (j > 0) {
    b[j] = a[i];
    i++;
    j -= 2;
  }

  long long ans1 = 0;
  for (int i = 0; i < n - 1; ++i) {
    ans1 += abs(b[i] - b[i + 1]);
  }

  i = 0;
  j = 2;
  while (j < n) {
    b[j] = a[i];
    i++;
    j += 2;
  }
  b[0] = a[i];
  i++;
  if (n % 2 == 0) {
    j--;
    b[j] = a[i];
    i++;
    j -= 2;
  } else {
    j -= 3;
  }
  while (j > 0) {
    b[j] = a[i];
    i++;
    j -= 2;
  }

  long long ans2 = 0;
  for (int i = 0; i < n - 1; ++i) {
    ans2 += abs(b[i] - b[i + 1]);
  }

  cout << max(ans1, ans2) << "\n";
  return 0;
}
