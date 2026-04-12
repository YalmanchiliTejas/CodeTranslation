#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    static int a[2 * 100000 + 10];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    static int b[2 * 100000 + 10];
    int x = n / 2 - 1;
    int y = n / 2;
    for (int i = 0; i < n; ++i) {
      if (i % 2) b[x--] = a[i];
      else b[y++] = a[i];
    }
    if (n % 2 == 0) {
      for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << b[i];
      }
      cout << endl;
    } else {
      for (int i = n - 1; 0 <= i; --i) {
        if (i - (n - 1)) cout << ' ';
        cout << b[i];
      }
      cout << endl;
    }
  }
  
  return 0;
}
