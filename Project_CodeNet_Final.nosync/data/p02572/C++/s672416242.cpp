#include<iostream>
typedef long long ll;
using namespace std;
int main () {
  int N;
  cin >> N;
  ll m = 1e9 + 7;
  ll wanoni = 0;
  ll ninowa = 0;
  for (int i = 0; i < N; i ++) {
    ll a;
    cin >> a;
    wanoni += a;
    a = a * a;
    a %= m;
    ninowa += a;
    wanoni %= m;
    ninowa %= m;
  }
  wanoni = wanoni * wanoni;
  wanoni %= m;
  ll ans = wanoni - ninowa;
  if (ans < 0) ans += m;
  ans *= 500000004;
  ans %= m;
  cout << ans << endl;
}