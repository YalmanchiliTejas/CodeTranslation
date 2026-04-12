#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
int main() {
  ll N,X,M;
  cin >> N >> X >> M;
  vector<ll> seq;
  map<ll,ll> mp;
  ll cnt = 1;
  seq.push_back(X);
  mp[X] = 1;
  ll now = X;
  ll len = 0;
  ll roops = 0;
  ll num = 0;
  while (0 == 0) {
    cnt++;
    now *= now;
    now %= M;
    seq.push_back(now);
    if (mp[now] != 0) {
      len = cnt - mp[now];
      roops = mp[now];
      num = now;
      break;
    } else {
      mp[now] = cnt;
    }
  }
  ll ans = 0;
  if (N <= cnt) {
    for (int i = 0; i < N; i++) {
      ans += seq[i];
    }
    
  } else {
    for (int i = 0; i < mp[num] - 1; i++) {
      ans += seq[i];
    }
    ll roopsum = 0;
    vector<ll> R(1);
    R[0] = 0;
    for (int i = mp[num] - 1; i < cnt - 1; i++) {
      roopsum += seq[i];
      R.push_back(R[(int)R.size() - 1] + seq[i]);
    }
    ans += ((N - mp[num] + 1) / len) * roopsum;
    ans += R[((N - mp[num] + 1) % len)];
    
  }
  cout << ans << endl;
  return 0;
}