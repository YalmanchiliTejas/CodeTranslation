#include <bits/stdc++.h>
#define int long long
#define rng(i, l, r) for (size_t i = (l); i < (r); ++i)
#define rep(i, n) rng(i, 0, n)
#define gnr(i, l, r) for (size_t i = (r)-1; i >= (l); i--)
#define per(i, b) gnr(i, 0, b)
#define ALL(obj) (obj).begin(), (obj).end()    //1,2,3,...
#define rALL(obj) (obj).rbegin(), (obj).rend() //...,3,2,1
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
using namespace std;
const int INF = 1e18;

void solve()
{

    // remove the bottom 3 lines when you submit this code.
    std::ifstream in("sample.txt");
    std::cin.rdbuf(in.rdbuf());

    cin.tie(0);
    ios::sync_with_stdio(false);

        int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = INF;
    for (int ab = 0; ab <= 200010; ab++)
    {
        int tmp = 0;
        tmp += ab * c;
        int da = max((int)0, x - ab / 2);
        int db = max((int)0, y - ab / 2);
        tmp += da * a + db * b;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}

signed main()
{
    solve();
    return 0;
}
