#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int A,B,C;
int X,Y;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> A >> B >> C;
  cin >> X >> Y;

  int AB = A + B;
  int C2 = 2 * C;

  ll pay = 0;
  int curMin = min(X,Y);
  
  // buy as many AB pizzas as possible
  if (C2 < AB) {
    pay += (C2 * curMin);
    X -= curMin;
    Y -= curMin;
  }

  if (C2 < A) pay += (C2 * X);
  else pay += (A * X);

  if (C2 < B) pay += (C2 * Y);
  else pay += (B * Y);

  cout << pay << endl;
  return 0;
}
