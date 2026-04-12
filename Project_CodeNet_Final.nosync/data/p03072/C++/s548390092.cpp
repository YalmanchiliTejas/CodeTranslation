#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;

    vector<int> h(n);
    rep (i, n)
        cin >> h[i];

    int ans = 1;
    int maxNum = h[0];
    rep (i, n - 1)
        if (h[i + 1] >= h[i] && h[i + 1] >= maxNum)
        {
            ans++;
            maxNum = max(h[i + 1], maxNum);
        }

    cout << ans << endl;
    return 0;
}