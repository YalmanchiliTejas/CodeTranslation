#include<bits/stdc++.h>
#define taskname ""
#define int long long
using namespace std;

const int maxn = 1e6;
const int lim = 1e9 + 7;

int n;
int a[maxn + 10];

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);
    if (ifstream("test.inp"))
    {
        freopen("test.inp", "r", stdin);
        #ifdef CHECKING
            freopen(taskname".out", "w", stdout);
        #else
            freopen("test.out", "w", stdout);
        #endif //CHECKING
    }
    else if (ifstream(taskname".inp"))
    {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }

    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum -= a[i];
        ans += ((a[i] % lim) * (sum % lim)) % lim;
        ans %= lim;
    }
    cout << ans;
}
