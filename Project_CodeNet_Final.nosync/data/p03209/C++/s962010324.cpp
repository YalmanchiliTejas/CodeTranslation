#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;

int n, x;
vector<int> pat, len;

int calc(int l, int x)
{
    if (x == 0)
        return 0;
    if (l == 0)
        return 1;
    int mid = (len[l] + 1) / 2;
    if (x < mid)
    {
        return calc(l - 1, x - 1);
    }
    x -= mid;
    return calc(l - 1, x) + pat[l - 1] + 1;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x;
    pat.resize(n + 1);
    len.resize(n + 1);
    pat[0] = 1, len[0] = 1;
    rep(i, n)
    {
        pat[i + 1] = 2 * pat[i] + 1;
        len[i + 1] = 2 * len[i] + 3;
    }
    cout << calc(n, x) << endl;
}