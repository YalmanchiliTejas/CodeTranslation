#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
int main()
{
  int N;
  cin >> N;
  vector<int> H(N);
  rep(i, N)
  {
    cin >> H[i];
  }
  int ans = 0;
  int mm = 0;
  for (int i = 0; i < N; i++)
  {
    mm = max(mm, H[i]);
    if (mm == H[i])
    {
      ans++;
    }
  }
  cout << ans << endl;
}