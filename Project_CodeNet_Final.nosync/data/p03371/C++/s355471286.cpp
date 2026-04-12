#include <bits/stdc++.h>
using namespace std;
int main()
{
  int A, B, C;	// Aピザ値段, Bピザ値段, ABピザ値段
  int X, Y;		// Aピザ枚数, Bピザ枚数
  cin >> A >> B >> C >> X >> Y;
  long long sum1 = 0;
  sum1 = (A * X) + (B * Y);	// AピザとBピザの値段合計初期値
  // 枚数の最大数ループ
  for(int i = 1; i <= max(X, Y); ++i)
  {
    long long sum2 = 2 * i;	// ABピザの枚数(2枚でAとBが1枚できる)
    long long sum3 = (C * sum2) + (A * max(0, X - i)) + (B * max(0, Y - i));	// AピザBピザの枚数を減らしてABピザに組み替えた合計金額を出す
    sum1 = min(sum1, sum3);	// 最小の値段を蓄積
  }
  cout << sum1 << endl;
  return 0;
}