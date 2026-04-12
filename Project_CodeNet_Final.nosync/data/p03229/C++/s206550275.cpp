#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;
int n;
int64_t a[MAX_N];

int main()
{
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a, a+n);

  int64_t s = a[n-1] - a[0];
  int i = 0, j = n-1;
  int k = 1, l = n-2;
  while (k <= l) {
    if (a[l] - a[i] > a[j] - a[k]) {
      s += a[l] - a[i];
      i++;
      l--;
    } else {
      s += a[j] - a[k];
      j--;
      k++;
    }
  }
  cout << s << endl;


  return 0;
}
