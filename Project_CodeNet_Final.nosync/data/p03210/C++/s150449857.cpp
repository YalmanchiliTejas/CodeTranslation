#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
//constexpr ll MOD = 998244353;
//constexpr ll MOD = ;
ll mod(ll A, ll M) {return (A % M + M) % M;}
constexpr ll INF = 1LL << 60;
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
ll divceil(ll A, ll B) {return (A + (B - 1)) / B;}
#define FINALANS(A) do {cout << (A) << '\n'; exit(0);} while (false)

int main()
{
  ll X;
  cin >> X;

  cout << ((X == 7 || X == 5 || X == 3) ? "YES" : "NO") << endl;
}