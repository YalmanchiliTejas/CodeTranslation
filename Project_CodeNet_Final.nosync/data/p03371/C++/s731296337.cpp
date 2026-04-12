#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;

template<class T> inline bool chmin(T &a, T b)
{
    if(a > b)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans = INF;

    // CでX, Yを満たす場合
    chmin(ans, 2*C * max(X, Y));
    // cout << ans << endl;

    // CでXを満たす場合
    chmin(ans, 2*C * X + max(0LL, B * (Y - X)));
    // cout << ans << endl;

    // CでYを満たす場合
    chmin(ans, 2*C * Y + max(0LL, A * (X - Y)));
    // cout << ans << endl;

    // Cを使わない場合
    chmin(ans, X*A + Y*B);
    // cout << ans << endl;

    cout << ans << endl;

    return 0;
}
