#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n, k;
  string s;
  cin >> n >> s >> k;
  rep(i, n) {
    if (s.at(i) == s.at(k-1)) cout << s.at(i);
    else cout << '*';
  }
  cout << endl;
}
