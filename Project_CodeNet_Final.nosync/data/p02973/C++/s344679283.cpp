#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = pow(10, 9) + 7;
//const ll MOD = 998244353;
//const ll MOD = ;
ll mod(ll A, ll M) {return (A % M + M) % M;}
const ll INF = 1LL << 60;
template<class T> bool chmin(T& a, T b) {if (a >= b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
ll divceil(ll A, ll B) {return (A + (B - 1)) / B;}
ll myctoi(char C) {return C - '0';}
char myitoc(ll N) {return '0' + N;}
#define FINALANS(A) {cout << (A) << endl; exit(0);}

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }

  vector<ll> LIS(N + 1, INF);
  LIS.at(0) = -INF;
  for (ll i = 0; i < N; i++)
  {
    ll ind = distance(LIS.begin(), upper_bound(LIS.begin(), LIS.end(), -A.at(i)));
    chmin(LIS.at(ind), -A.at(i));
  }

  ll ans = -1 + distance(LIS.begin(), lower_bound(LIS.begin(), LIS.end(), INF));
  cout << ans << endl;

  /*
  for (ll i = 0; i < N + 1; i++)
  {
    cerr << LIS.at(i) << endl;
  }
  */
}