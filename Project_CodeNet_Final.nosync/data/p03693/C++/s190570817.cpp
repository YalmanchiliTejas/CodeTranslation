#include <bits/stdc++.h>
using namespace std;
#define ll long long
template <typename T>
bool PN(T x){ if (x <= 1) return false; if (x == 2) return true; for (int i = 2; i < sqrt(x) + 1; i++) if (x % i == 0) return false; return true;}
const ll MOD = 1e9+7;
long long Comb(int n, int i){long long ans = 1; if(i == 0 || i == n) return 1; else {for(int j = 1; j <= i; ++j){
      ans *=(n+1-j);
      ans /= j;
      ans %= MOD;} }return ans;}

void solve()
{
  int a, b, c; cin >> a >> b >> c;
  int sum = 100 * a + 10 * b + c;
  if(sum%4 == 0)cout << "YES" << endl;
  else cout << "NO" << endl;

}

int main()
{
  solve();
  return 0;
}
