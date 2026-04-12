#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i < b; i++)
#define re(i, n) fo(i, 0, n)
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  vector<int> h(n);
  re(i, n) cin >> h[i];

  int c = 1;
  int max = h[0];
  fo(i, 1, n) {
    if (max <= h[i]) {
      c++;
      max = h[i];
    }
  }

  cout << c << endl;

  return 0;
}
