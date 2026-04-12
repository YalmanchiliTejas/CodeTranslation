#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  int H;
  int ans = 0;
  int max = 0;

  for (int i = 0; i < N; i++)
  {
    cin >> H;

    if (H >= max)
    {
      max = H;
      ans++;
    }
  }

  cout << ans << endl;
}
