#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod 100000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
ll lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout << fixed << setprecision(15);
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll ave = A + B / 2;
    ll ans = 0;
    if (C * 2 < A + B)
    {
        ans = min(X, Y) * C * 2;
        if (X < Y)
        {
            ans += (Y - X) * min(2 * C, B);
        }
        else if (X > Y)
        {
            ans += (X - Y) * min(2 * C, A);
        }
    }
    else
    {
        ans += X * A + Y * B;
    }
    cout << ans << endl;
}