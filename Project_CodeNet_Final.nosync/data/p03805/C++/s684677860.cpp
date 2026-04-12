#include <iostream>
#include <cstring>

using namespace std;

int rec(int pos, int mul, int m);

int prime[] = {2, 3, 5, 7, 11, 13, 17, 19};

int cnt = 0;

int n, m;

int a[28], b[28];

int mulmax = 1;

int main(void) {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    mulmax = mulmax * prime[i];
  }

  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
  }

  rec(1, 2, m);

  cout << cnt << endl;
  return 0;
}

int rec(int pos, int mul, int m) {
  if (mul >= mulmax) {
    cnt++;
    return 0;
  }

  for (int i = 0; i < m; i++) {
    if (a[i] == pos && mul % prime[b[i] - 1] != 0) rec(b[i], mul * prime[b[i] - 1], m);
    if (b[i] == pos && mul % prime[a[i] - 1] != 0) rec(a[i], mul * prime[a[i] - 1], m);
  }
}