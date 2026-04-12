#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 100;

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int ways1 = X * A + Y * B;
    int ways2 = X < Y ? C * X * 2 + (Y - X) * B : C * Y * 2 + (X - Y) * A;
    // cout << ways1 << " " << ways2 << endl;
    int ways3 = X > Y ? C * X * 2 : C * Y * 2;
    int ans = ways1 < ways2 ? ways1 : ways2;
    ans = ans < ways3 ? ans : ways3;
    cout << ans << endl;
    return 0;
}
