#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
using ll = long long ;
int n, a[nax];

ll const inf = 1e18;

ll ans;

ll e[nax], o[nax];

ll dp[nax][3];


int main () {
    scanf("%d", &n);

    ll esum = 0, osum = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", a + i);
    }

    for (int i = 0 ; i <= n ; ++ i) {
        for (int j = 0 ; j < 3 ; ++ j)
            dp[i][j] = -inf;
    }

    dp[0][0] = 0;
    dp[1][0] = a[1];
    dp[2][1] = a[2];

    for (int i = 3 ; i <= n ; ++ i) {
        dp[i][0] = max(dp[i][0], dp[i - 2][0] + a[i]);
        dp[i][1] = max(dp[i][1], dp[i - 2][1] + a[i]);
        dp[i][2] = max(dp[i][2], dp[i - 2][2] + a[i]);

        if (i >= 3) dp[i][1] = max(dp[i][1], dp[i - 3][0] + a[i]);
        if (i >= 4) dp[i][2] = max(dp[i][2], dp[i - 4][0] + a[i]);
        if (i >= 3) dp[i][2] = max(dp[i][2], dp[i - 3][1] + a[i]);
    }

    if (n % 2 == 0) {
        printf("%lld\n", max({ dp[n][1], dp[n][0], dp[n - 1][0]}));
    } else {
        printf("%lld\n", max({dp[n - 2][0], dp[n - 1][1], dp[n][2], dp[n][1]}));
    }


}
/*
    Good Luck
        -Lucina
*/
