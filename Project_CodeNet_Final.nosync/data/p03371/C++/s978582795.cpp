#include<bits/stdc++.h>
constexpr long long INFL = 1LL << 60;
constexpr int INF = 1e9;

using namespace std;

int main()
{
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    int all_c = max(X, Y) * 2 * C;
    int else_is_c;
    if(Y >= X)
        else_is_c = X * 2 * C + (Y - X) * B;
    else
        else_is_c = Y * 2 * C + (X - Y) * A;
    int a_b = A * X + B * Y;

    int ans = min({all_c, else_is_c, a_b});

    cout << ans << endl;

    return 0;
}