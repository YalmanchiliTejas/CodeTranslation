#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll N, X, M;
  cin >> N >> X >> M;
  vector<bool> f(M,false);
  vector<ll> calc(M);
  calc[0] = X;
  f[X] = true;
  ll now = 0;
  for (now = 1; now < min(M, N); now++) {
    calc[now] = calc[now-1] * calc[now-1] % M;
    if (f[calc[now]]) break;
    else f[calc[now]] = true;
  }
  ll ans = 0;
  if (now != (M-1)) {
    ll loop = 0;
    rep(i,now) {
      if (calc[i] == calc[now]) {
        loop = i;
        break;
      }
    }
    ll temp = 0;
    for (ll i = loop; i < now; i++){
      temp += calc[i];
    }
    ll x = (N - loop)/(now-loop);
    ans += x*temp;
    rep(i, loop) ans += calc[i];
    ll y = (N - loop) % (now - loop);
    for (ll i = loop; i < loop+y; i++) ans += calc[i];
  } else{
    rep(i,N) ans += calc[i];
  }
  cout << ans << endl;
  return 0;
}