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
  ll A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  ll ans = INF;
  chmin(ans, 2 * C * X + B * max(0LL, Y - X));
  chmin(ans, 2 * C * Y + A * max(0LL, X - Y));
  chmin(ans, A * X + B * Y);
  cout << ans << endl;
}