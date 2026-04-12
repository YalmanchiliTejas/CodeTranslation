#include <iostream>
using namespace std;

int main()
{
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int ans = 0;
  for(;;) {
    if(X <= 0 && Y <= 0) {
      cout << ans << endl;
      return 0;
    }

    if(X > 0 && Y > 0) {
      ans += min(A+B, C*2);
      --X;
      --Y;
    }
    else if (X > 0 && Y <= 0) {
      ans += min(A, C*2);
      --X;
    }
    else {
      ans += min(B, C*2);
      --Y;
    }
  }
}
