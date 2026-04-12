#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, X;

ll leng[51];
ll pat[51];

ll res(ll n, ll x) {
  if (n == 0 && x == 1) return 1;
  if (n == 0 && x == 0) return 0;
  if (x <= 1) {
    return 0;
  } else if (x <= 1+leng[n-1]) {
    return res(n-1, x-1);
  } else {
    return pat[n-1] + 1 + res(n-1, x-2-leng[n-1]);
  }
}

int main() {
  cin >> N >> X;
  leng[0] = 1; pat[0] = 1;
  for (ll i = 1; i <= N; i++) {
    leng[i] = 2*leng[i-1]+3;
    pat[i] = 2*pat[i-1]+1;
  }
  cout << res(N, X) << endl;
}