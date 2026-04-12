#include <bits/stdc++.h>
using namespace std;
#define INFTY 1000000000

int main()
{
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int m = INFTY;
  // O(max(X, Y))のアルゴリズム
  for (int i = 0; i <= max(X, Y); i++)
  {
    // 2i枚ABピザを買う時の料金
    int tmp = C * (2 * i);
    if (X - i > 0)
    {
      tmp += A * (X - i);
    }
    if (Y - i > 0)
    {
      tmp += B * (Y - i);
    }
    m = min(m, tmp);
  }
  cout << m << endl;
}