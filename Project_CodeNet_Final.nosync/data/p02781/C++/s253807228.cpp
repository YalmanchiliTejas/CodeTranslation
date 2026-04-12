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
#define FINALANS(A) do {cout << (A) << '\n'; exit(0);} while (false)

int main()
{
  string N;
  cin >> N;
  ll K;
  cin >> K;

  vector<vector<vector<ll>>> dp(201, vector<vector<ll>>(5, vector<ll>(2, 0)));
  dp.at(0).at(0).at(0) = 1;
  for (ll i = 0; i < N.size(); i++)
  {
    for (ll j = 0; j <= 3; j++)
    {
      for (char d = '0'; d <= '9'; d++)
      {
        ll nj = ((d == '0') ? j : j + 1);

        if (d < N.at(i))
        {
          dp.at(i + 1).at(nj).at(1) += dp.at(i).at(j).at(0);
          dp.at(i + 1).at(nj).at(1) += dp.at(i).at(j).at(1);
        }
        else if (d == N.at(i))
        {
          dp.at(i + 1).at(nj).at(0) += dp.at(i).at(j).at(0);
          dp.at(i + 1).at(nj).at(1) += dp.at(i).at(j).at(1);
        }
        else
        {
          dp.at(i + 1).at(nj).at(1) += dp.at(i).at(j).at(1);
        }
      }
    }
  }

  ll ans = dp.at(N.size()).at(K).at(0) + dp.at(N.size()).at(K).at(1);
  cout << ans << endl;
}