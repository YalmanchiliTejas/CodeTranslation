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

int main()
{
  string K;
  ll D;
  cin >> K >> D;
  ll N = K.size();

  vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(D, vector<ll>(2, 0)));
  dp.at(0).at(0).at(0) = 1;
  for (ll i = 0; i < N; i++)
  {
    for (ll j = 0; j < D; j++)
    {
      for (ll k = 0; k < 10; k++)
      {
        ll nj = (j + k) % D;

        // 0: i 桁目の数字が, K の i 桁目を越えてはいけない
        if (k == myctoi(K.at(i)))
        {
          dp.at(i + 1).at(nj).at(0) += dp.at(i).at(j).at(0);
          dp.at(i + 1).at(nj).at(0) %= MOD;
        }
        if (k < myctoi(K.at(i)))
        {
          dp.at(i + 1).at(nj).at(1) += dp.at(i).at(j).at(0);
          dp.at(i + 1).at(nj).at(1) %= MOD;
        }

        // 1: i 桁目の数字が, K の i 桁目を越えてもよい
        dp.at(i + 1).at(nj).at(1) += dp.at(i).at(j).at(1);
        dp.at(i + 1).at(nj).at(1) %= MOD;
      }
    }
  }

  /*
  for (ll i = 0; i < N + 1; i++)
  {
    for (ll j = 0; j < D; j++)
    {
      cerr << dp.at(i).at(j).at(0) << " ";
    }
    cerr << endl;
  }
  cerr << endl;
  for (ll i = 0; i < N + 1; i++)
  {
    for (ll j = 0; j < D; j++)
    {
      cerr << dp.at(i).at(j).at(1) << " ";
    }
    cerr << endl;
  }
  */

  ll ans = (dp.at(N).at(0).at(0) + dp.at(N).at(0).at(1) + MOD - 1) % MOD;
  cout << ans << endl;
}