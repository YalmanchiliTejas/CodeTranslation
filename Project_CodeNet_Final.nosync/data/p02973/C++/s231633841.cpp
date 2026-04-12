#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../lib/dump.hpp"
#else
#define dump(...)
#define dumpv(...)
#endif

typedef long long ll;
typedef pair<int, int> P;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  // freopen("temp.1", "r", stdin);

  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  vector<int> m(N);
  int cnt = 0;
  int mn = 0;
  for (int i = 0; i < N; i++) {
    int found = false;
    if (mn < a[i]) {
      for (int j = 0; j < cnt; j++) {
        if (m[j] < a[i]) {
          m[j] = a[i];
          found = true;
          break;
        }
      }
    }
    if (!found) {
      m[cnt] = a[i];
      mn = a[i];
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}