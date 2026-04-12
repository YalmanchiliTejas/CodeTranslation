#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = 1e9 + 7;

int n, a;
long long s, ans;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (i) {
      long long tmp = a * s;
      tmp %= MOD;
      ans += tmp;
      ans %= MOD;
    }
    s += a;
    s %= MOD;
  }
  cout << ans << E;
  //system("pause");
  return 0;
}