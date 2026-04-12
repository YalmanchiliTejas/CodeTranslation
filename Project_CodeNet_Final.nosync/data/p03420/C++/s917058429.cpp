#include<bits/stdc++.h>

using namespace std;

const int MaxN = 2e5 + 25;
const int MOD = 1e9 + 7;


int main()
{
//    freopen("input.txt", "r", stdin);

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    if(k == 0)
    {
        cout << n * 1ll * n << '\n';
        return 0;
    }

    long long ans = 0;

    for(int a = max(k, 1); a <= n; ++a)
    {
        for(int l = 0; l <= n; l += a)
        {
            int r = l + a - 1;
            if(r <= n)
                ans += (a - k);
            else
            {
                int len = n - l + 1;
                if(len >= k)
                    ans += len - k;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
