#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;
//const ll MOD = ;
ll mod(ll A, ll M) {return (A % M + M) % M;}
const ll INF = 1LL << 60;
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
ll divceil(ll A, ll B) {return (A + (B - 1)) / B;}
ll myctoi(char C) {return C - '0';}
char myitoc(ll N) {return '0' + N;}
#define FINALANS(A) {cout << (A) << '\n'; exit(0);}

class combination
{
public:
  vector<ll> fac, finv, inv;

  combination(ll M)
  {
    fac = vector<ll>(M, 1);
    finv = vector<ll>(M, 1);
    inv = vector<ll>(M, 1);

    for (ll i = 2; i < M; i++)
    {
      fac.at(i) = fac.at(i - 1) * i % MOD;
      inv.at(i) = MOD - inv.at(MOD % i) * (MOD / i) % MOD;
      finv.at(i) = finv.at(i - 1) * inv.at(i) % MOD;
    }
  }

  ll P(ll N, ll K)
  {
    if (N < K) return 0;
    if (N < 0 || K < 0) return 0;
    return fac.at(N) * finv.at(N - K) % MOD;
  }

  ll C(ll N, ll K)
  {
    if (N < K) return 0;
    if (N < 0 || K < 0) return 0;
    return fac.at(N) * (finv.at(K) * finv.at(N - K) % MOD) % MOD;
  }

  ll H(ll N, ll K)
  {
    return C(N + K - 1, K);
  }
};

int main()
{
  ll N, M, K;
  cin >> N >> M >> K;

  combination com(N * M);

  ll ans = 0;
  for (ll i = 0; i < N; i++)
  {
    for (ll j = 0; j < M; j++)
    {
      if (i != 0 && j != 0)
        ans += 2 * (N - i) * (M - j) * (i + j);
      else
        ans += (N - i) * (M - j) * (i + j);
      ans %= MOD;
    }
  }

  ans *= com.C(N * M - 2, K - 2);
  ans %= MOD;

  cout << ans << endl;
}