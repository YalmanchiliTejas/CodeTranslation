#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[3005];
ll pre[3005];
ll dp[3005][3005];

ll sm(int i, int j){
    if (i > j) return 0;
    return (pre[j] - (i > 0 ? pre[i-1] : 0));
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pre[i] = a[i] + (i ? pre[i-1] : 0);
    }



    for (int l = 0; l < n; l++)
    {
        for (int i = 0; i+l < n; i++)
        {
            int j = i+l;
            dp[i][j] = max(a[i] + sm(i+1, j) - dp[i+1][j],
                           a[j] + sm(i, j-1) - dp[i][j-1]);
        }
    }

    cout << dp[0][n-1] - (sm(0, n-1) - dp[0][n-1]);

    return 0;
}
