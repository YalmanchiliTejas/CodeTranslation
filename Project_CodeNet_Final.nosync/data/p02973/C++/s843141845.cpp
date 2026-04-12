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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> v;
    v.push_back(-a[0]);
    Rep(i, 1, n)
    {
        int pos = upper_bound(all(v), -a[i]) - v.begin();
        if (pos == v.size())
            v.push_back(-a[i]);
        else
            v[pos] = -a[i];
    }
    cout << v.size() << endl;
}