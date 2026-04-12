#include <iostream>
#include <algorithm>
using namespace std;

int A,B,C,X,Y;
void input()
{
    cin >> A >> B >> C >> X >> Y;
}

void solve()
{
    int MIN = min(X,Y);
    int ans = min(A + B, C * 2) * MIN;
    X -= MIN;
    Y -= MIN;
    ans += min(A, C * 2) * X + min(B, C * 2) * Y;
    cout << ans << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}