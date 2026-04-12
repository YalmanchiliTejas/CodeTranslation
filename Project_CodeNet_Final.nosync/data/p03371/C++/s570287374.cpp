#include<bits/stdc++.h>

using namespace std;


int main()
{
    long long A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
    C *= 2;

    long long ans = 0;

    ans = max(X, Y) * C;

    ans = min(ans, A * X + B * Y);

    ans = min(ans, (X < Y ? X * C + (Y - X) * B : Y * C + (X - Y) * A));

    cout << ans << endl;
}