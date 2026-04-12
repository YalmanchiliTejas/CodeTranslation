#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int a[n], c = 0, max = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (max <= a[i] || i == 0) {
      c++;
    }
    if (max < a[i]) {
      max = a[i];
    }
  }
  cout << c << endl;
}