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
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    if (n % 2 == 0)
    {
        for (int i = n - 1; i >= 0; i -= 2)
            cout << a[i] << " ";
        for (int i = 0; i < n; i += 2)
            cout << a[i] << " ";
        cout << endl;
    }
    else
    {
        for (int i = n - 1; i >= 0; i -= 2)
            cout << a[i] << " ";
        for (int i = 1; i < n; i += 2)
            cout << a[i] << " ";
        cout << endl;
    }
}