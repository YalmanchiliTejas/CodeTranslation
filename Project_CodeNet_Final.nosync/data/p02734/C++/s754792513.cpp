#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//constexpr ll MOD = 1e9 + 7;
constexpr ll MOD = 998244353;
//constexpr ll MOD = ;
ll mod(ll A, ll M) {return (A % M + M) % M;}
constexpr ll INF = 1LL << 60;
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
ll divceil(ll A, ll B) {return (A + (B - 1)) / B;}
#define FINALANS(A) do {cout << (A) << '\n'; exit(0);} while (false)

class mll
{
public:
  ll x;
  constexpr mll(ll x = 0) : x((x % MOD + MOD) % MOD) {}
  constexpr mll operator-() const
  {
    return mll(-x);
  }
  constexpr mll& operator+=(const mll& a)
  {
    x += a.x;
    if (x >= MOD)
      x -= MOD;
    return *this;
  }
  constexpr mll& operator-=(const mll& a)
  {
    x += MOD - a.x;
    if (x >= MOD)
      x -= MOD;
    return *this;
  }
  constexpr mll& operator*=(const mll& a)
  {
    x *= a.x;
    x %= MOD;
    return *this;
  }
  constexpr mll operator+(const mll& a) const
  {
    mll ret(*this);
    ret += a;
    return ret;
  }
  constexpr mll operator-(const mll& a) const
  {
    mll ret(*this);
    ret -= a;
    return ret;
  }
  constexpr mll operator*(const mll& a) const
  {
    mll ret(*this);
    ret *= a;
    return ret;
  }
  constexpr mll pow(ll t) const
  {
    mll ret = 1;
    mll a = *this;
    while (t > 0)
    {
      if (t % 2 == 1)
        ret *= a;
      
      a *= a;
      t /= 2;
    }
    return ret;
  }
  constexpr mll inv() const
  {
    return pow(MOD - 2);
  }
  constexpr mll& operator/=(const mll& a)
  {
    return (*this) *= a.inv();
  }
  constexpr mll operator/(const mll& a) const
  {
    mll ret(*this);
    ret /= a;
    return ret;
  }
};
ostream& operator<<(ostream& os, const mll& m)
{
  os << m.x;
  return os;
}

int main()
{
  ll N, S;
  cin >> N >> S;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }

  vector<vector<vector<mll>>> dp(N + 1, vector<vector<mll>>(S + 1, vector<mll>(3, 0)));
  dp.at(0).at(0).at(0) = 1;
  for (ll i = 0; i < N; i++)
  {
    ll a = A.at(i);
    for (ll j = 0; j <= S; j++)
    {
      dp.at(i + 1).at(j).at(0) += dp.at(i).at(j).at(0);
      dp.at(i + 1).at(j).at(1) += dp.at(i).at(j).at(0);
      dp.at(i + 1).at(j).at(1) += dp.at(i).at(j).at(1);
      if (j == S)
        dp.at(i + 1).at(j).at(2) += dp.at(i).at(j).at(1);
      dp.at(i + 1).at(j).at(2) += dp.at(i).at(j).at(2);

      if (j + a > S)
        continue;

      dp.at(i + 1).at(j + a).at(1) += dp.at(i).at(j).at(0);
      dp.at(i + 1).at(j + a).at(1) += dp.at(i).at(j).at(1);
      if (j + a == S)
      {
        dp.at(i + 1).at(j + a).at(2) += dp.at(i).at(j).at(1);
        dp.at(i + 1).at(j + a).at(2) += dp.at(i).at(j).at(0);
      }
    }
  }
  cout << dp.at(N).at(S).at(2) << endl;
  
  /*
  for (ll i = 0; i <= N; i++)
  {
    for (ll j = 0; j <= S; j++)
    {
      cerr << "(";
      for (ll k = 0; k < 3; k++)
      {
        cerr << dp.at(i).at(j).at(k) << ((k == 2) ? ") " : ", ");
      }
    }
    cerr << endl;
  }
  //*/
}