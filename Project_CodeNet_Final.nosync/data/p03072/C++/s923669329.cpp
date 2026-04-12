#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
// const ll INF = 1LL<<60;
const long long INF = 1LL<<60; // 仮想的な無限大の値


int main()
{
  ll N;cin>>N;

  vector<ll> H(N);
  rep(i,N) cin>>H[i];

  vector<ll> S(N+1, 0);
  rep(i, N) S[i+1] = max(S[i], H[i]);

  ll ans = 0;
  rep(i, N) if (H[i] >= S[i+1]) ans ++;

  cout << ans << endl;
  return 0;
}