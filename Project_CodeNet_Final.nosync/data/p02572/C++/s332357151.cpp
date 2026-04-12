#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const int MOD = 1000000007;


int main() {
ll n;
cin >> n;
vector<ll> vec(n);
cin >> vec.at(0);
ll cnt = vec.at(0),ans = 0;

for (int i = 1;i < n;i++) {
  cin >> vec.at(i);
  ans += vec.at(i) * cnt;
  ans %= MOD;
  cnt = cnt + vec.at(i);
  cnt %= MOD;
}

cout << ans << endl;

return 0;
}

