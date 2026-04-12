#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 107;

int n, m;
int l[M], r[M];
string s[M];

void read() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> s[i];
}

void no() {
  cout << "Impossible\n";
  exit(0);
}

void yes() {
  cout << "Possible\n";
  exit(0);
}


void kill() {
  for (int i = 0; i < n; ++i) {
    l[i] = 0;
    r[i] = m - 1;
    while (l[i] < m && s[i][l[i]] == '.')
      ++l[i];
    while (r[i] >= 0 && s[i][r[i]] == '.')
      --r[i];

    if (l[i] > r[i])
      no();

    for (int j = l[i]; j <= r[i]; ++j)
      if (s[i][j] != '#')
        no();
  }

  if (l[0] != 0)
    no();
  if (r[n - 1] != m - 1)
    no();

  for (int i = 0; i + 1 < n; ++i)
    if (r[i] != l[i + 1])
      no();

  yes();
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}
