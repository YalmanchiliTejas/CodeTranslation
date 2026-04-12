#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAX = 1e5+5;
LL a[MAX];

int main()
{
        int n;
        cin >> n;
        LL sum = 0;
        for(int i = 1 ; i <= n ; i++)
        {
                cin >> a[i];
                sum += a[i];
        }
        LL dp[n+2][n+2];
        for(int gap = 0 ; gap <= n ; gap++)
        {
                for(int i = 1,j = gap ; j <= n ; i++,j++)
                {
                        LL x = (i+2 <= j)?dp[i+2][j]:0;
                        LL y = (i+1 <= j-1) ? dp[i+1][j-1]:0;
                        LL z = (i <= j-2) ? dp[i][j-2]:0;
                        dp[i][j] = max(a[i] + min(x,y) , a[j] + min(y,z));
                }
        }
        LL first = dp[1][n];
        LL second = sum - dp[1][n];
        cout << first - second << endl;
}
