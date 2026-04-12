#include <bits/stdc++.h>
using namespace std;
const int64_t MOD = 1000000007;

int main()
{
  int64_t N, ans = 0;
  cin >> N;
  vector<int64_t> A(N), S(N + 1, 0); // S.at(r) - S.at(l); [l, r)
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
    S.at(i + 1) = (S.at(i) + A.at(i)) % MOD;
  }
  for (int i = 0; i < N; i++)
  {
    ans += (A.at(i) * ((S.at(N) - S.at(i + 1) + MOD) % MOD)) % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}