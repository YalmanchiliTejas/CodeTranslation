#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define ppb pop_back
#define INF 1e18
typedef long long ll;

using namespace std;

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, ab, x, y;
    cin >> a >> b >> ab >> x >> y;
    ll ans = 0;
    while (x > 0 and y > 0)
    {
        x--;
        y--;
        ans += min(2*ab, a + b);
    }
    while (x > 0)
    {
        x--;
        ans += min(a, 2*ab);
    }
    while (y > 0)
    {
        y--;
        ans += min(b, 2*ab);
    }

    cout<<ans<<endl;

    return 0;
}