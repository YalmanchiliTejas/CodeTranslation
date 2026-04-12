#define taskname ""

#include <iostream>
#include <algorithm>

using namespace std;
#define long long long

const int N = 3e3 + 10;

int n, a[N];
long f[N][N];

int main()
{
//    freopen(taskname".INP", "r", stdin);
//    freopen(taskname".OUT", "w", stdout);
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int r = 1; r <= n; ++r)
        for (int l = r; l > 0; --l)
            f[l][r] = max(a[l] - f[l + 1][r], a[r] - f[l][r - 1]);

    cout << f[1][n];

    return 0;
}
