#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define Repr(i, n, a) for (int i = (n); i >= (a); i--)
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

    int n;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        vector<int> v(n);
        rep(i, n) cin >> v[i];
        sort(all(v));
        int sum = 0;
        for (int i = 1; i < n - 1; i++)
            sum += v[i];
        cout << sum / (n - 2) << endl;
    }
}
