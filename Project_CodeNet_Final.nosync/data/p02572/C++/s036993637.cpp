#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const long long INF = 1LL<<60;

typedef pair<ll,ll> Pair;

int main(){

  ll N;
  ll ans = 0;
  ll mod = 1e9 + 7;
  cin >> N;

  vector<ll> A(N);
  vector<ll> S(N + 1);

  for (ll i = 0; i < N;++i)
    cin >> A[i];

  S[0] = 0;

  for (ll i = 0; i <N;++i){

    S[i + 1] = (S[i] + A[i]);

  }

  for (ll i = 0; i < N;++i){
    ll tmp = (S[N] - S[i + 1]) % mod;
    ans += tmp*A[i];
    ans %= mod;
  }

  cout << ans << endl;

  return 0;

}   
