// AtCoder Beginner Contest 095 - Problem C: Half and half (https://atcoder.jp/contests/abc095/tasks/arc096_a) 
#include <bits/stdc++.h>

using namespace std;

int solve(int A, int B, int C, int X, int Y)
{
    if (2*C >= A + B)
        return X*A + Y*B;

    auto m = min(X, Y);
    auto ans = 2*C*m;

    X -= m;
    Y -= m;

    ans += (A <= 2*C) ? A*X : 2*C*X;
    ans += (B <= 2*C) ? B*Y : 2*C*Y;
    
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    auto ans = solve(A, B, C, X, Y);

    cout << ans << '\n';

    return 0;
}
