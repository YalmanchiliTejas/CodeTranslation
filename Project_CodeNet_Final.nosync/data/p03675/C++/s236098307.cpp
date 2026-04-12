#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;

int a[maxn]; int n;
int b[maxn];

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) b[i/2] = a[n-i-1];
    else b[n-i/2-1] = a[n-i-1];
  }
  for (int i = 0; i < n; i++) cout << b[i] << " ";
  cout << endl;
  return 0;
}
