#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(20);

  int x;
  cin >> x;

  if (x == 3 || x == 5 || x == 7) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
