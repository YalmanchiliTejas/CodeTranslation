#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, n, m) for (int i = n; i < m; i++)
#define ll long long int

using namespace std;

int main()
{
  int n;
  int h[100];
  cin >> n;
  REP(i,n) {
    cin >> h[i];
  }

  int result = 0;
  int m = -1;
  REP(i,n) {
    if (h[i] >= m) {
      result++;
      m = h[i];
    }
  }
  cout << result << endl;

}
