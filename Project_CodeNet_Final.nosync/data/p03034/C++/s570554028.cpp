#include "bits/stdc++.h"

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long> as(n);
    for (int i = 0; i < n; i++)
    {
        cin >> as[i];
    }
    long ans = 0;
    vector<int> vst(n);
    for (int d = 1; d <= (n - 1) / 2; d++)
    {
        long res = 0;
        fill(vst.begin(), vst.end(), 0);
        for (int k = 0; (k + 1) * d < n; k++)
        {
            int l = k * d, r = n - 1 - l;
            if (vst[l] || vst[r] || l == r)
                break;
            vst[l] = vst[r] = 1;
            res += as[l] + as[r];
            ans = max(ans, res);
        }
    }
    cout << ans << endl;
}

int main()
{
    solve();
    cerr << "\"努力不足ですね！\"" << endl;
    return 0;
}