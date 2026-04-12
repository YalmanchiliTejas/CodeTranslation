#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = a; i < n; i++)
#define Repr(i, n, a) for (int i = n; i >= a; i--)
#define rep(i, n) Rep(i, 0, n)
#define repr(i, n) Repr(i, n, 0)
#define all(a) a.begin(), a.end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    int cnt = 0;
    rep(i, h)
    {
        string s;
        cin >> s;
        rep(i, w) if (s[i] == '#') cnt++;
    }
    cout << (cnt == h + w - 1 ? "Possible" : "Impossible") << endl;
}