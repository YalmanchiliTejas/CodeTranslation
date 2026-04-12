


#include <bits/stdc++.h>

#define loop(s, e, i) for (int i = s; i < e; ++i)
#define print(s) cout << s << endl;
#define DIV 1000000007
#define ll = long long
using namespace std;

/*
浮動小数点の入力
cout << fixed << setprecision(9) << endl;
*/

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int both = min(X, Y);
  int both_cost = min(A+B, 2*C);

  int left_X = X - both;
  int left_Y = Y - both;

  int x_cost = min(A, 2*C);
  int y_cost = min(B, 2*C);

  int total_cost = both * both_cost + left_X * x_cost + left_Y * y_cost;
  print(total_cost);
}
