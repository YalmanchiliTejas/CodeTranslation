#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
#define rep(i, n) for(ll i = 0;i < n;i++)
#define FOR(i, m, n) for(ll i = m;i < n;i++)

int main() {
  cin.tie(0); ios::sync_with_stdio(false);

  int x;
  cin >> x;

  if (x == 3 || x == 5 || x == 7) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

}