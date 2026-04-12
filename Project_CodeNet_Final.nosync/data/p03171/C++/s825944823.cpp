#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//const ll MOD = 1e9 + 7;
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

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }

  vector<vector<ll>> dp(N + 1, vector<ll>(N + 1));
  for (ll i = 0; i < N; i++)
  {
    dp.at(i).at(i) = 0;
  }

  for (ll len = 1; len <= N; len++)
  {
    for (ll i = 0; i < N; i++)
    {
      ll j = i + len;
      if (j < 0 || N < j)
        continue;

      if ((N - len) % 2 == 0)
      {
        dp.at(i).at(j) = -INF;
        chmax(dp.at(i).at(j), dp.at(i + 1).at(j) + A.at(i));
        chmax(dp.at(i).at(j), dp.at(i).at(j - 1) + A.at(j - 1));
      }
      else
      {
        dp.at(i).at(j) = INF;
        chmin(dp.at(i).at(j), dp.at(i + 1).at(j) - A.at(i));
        chmin(dp.at(i).at(j), dp.at(i).at(j - 1) - A.at(j - 1));
      }
    }
  }

  ll ans = dp.at(0).at(N);
  cout << ans << endl;
}