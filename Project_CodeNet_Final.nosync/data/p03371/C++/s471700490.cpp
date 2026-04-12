#include <iostream>
using namespace std;
int main()
{
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int ans = INT32_MAX;
  for (int i = 0; i <= max(X, Y); i++)
  {
    int tmp = 2 * C * i + A * max(0, X - i) + B * max(0, Y - i);
    if (tmp < ans)
      ans = tmp;
  }
  cout << ans << endl;
  return 0;
}