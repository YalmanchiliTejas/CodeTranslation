#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n;
  cin >> n;
  ll res = 0, max = 0;
  rep(i, n) {
    ll a;
    cin >> a;
    if (max <= a) {
      res++;
      max = a;
    }
  }
  cout << res << endl;
}