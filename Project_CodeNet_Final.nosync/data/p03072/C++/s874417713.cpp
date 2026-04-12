#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define print(x) cout << x << endl;
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int h[n];
    int m = 0;
    int res = 0;
    rep(i, n) {
        cin >> h[i];
        if (h[i] >= m) ++res;
        m = max(m, h[i]);
    }

    cout << res << endl;

    return 0;
}