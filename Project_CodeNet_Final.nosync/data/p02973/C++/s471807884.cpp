#include <bits/stdc++.h>
using namespace std;

#define long long long
#define INF 0x3f3f3f3f
#define MAX_N 1000010

int dp[MAX_N], a[MAX_N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;

    while(cin >> n)
    {
        for(int i = 1; i <= n; i++)
        {
           cin >> a[i];
           a[i]=-a[i];
        }

        int len = 1;
        dp[len] = a[1];
        for(int i = 2; i <= n; i++)
        {
            if(a[i] >= dp[len])
            {
                dp[++len] = a[i];
            }
            else
            {
                int pos = upper_bound(dp+1, dp + len+1, a[i]) - dp;
                dp[pos] = a[i];
            }
        }
        cout << len << endl;
        break;
    }

    return 0;
}
