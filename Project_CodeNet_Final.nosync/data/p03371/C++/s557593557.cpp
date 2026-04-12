#include <iostream>
using namespace std;
int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int x = max(X, Y);
    int n = min(X, Y);
    int c2 = C * 2;

    int ans = min(A * X + B * Y, c2 * x);
    ans = min(ans, c2 * n + A * max(0, X - n) + B * max(0, Y - n));
    cout << ans << endl;

    return 0;
}
