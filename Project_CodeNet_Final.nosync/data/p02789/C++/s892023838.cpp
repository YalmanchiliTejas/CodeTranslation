#include <bits/stdc++.h>
#define rep(i, n) for (ll(i) = 0; (i) < (n); (i)++)
#define all(x) (x).begin(), (x).end()
#define print(x) cout << (x) << endl;

typedef long long ll;
const ll INF = 99999999999999;
const ll MOD = 1000000007;
const double PI = acos(-1.0);

using namespace std;

int main()
{
    int n, m;
    string ans = "Yes";
    cin >> n >> m;
    if (n != m)
    {
        ans = "No";
    }
    cout << ans << endl;
    return 0;
}