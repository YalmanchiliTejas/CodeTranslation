#pragma GCC optimize "-O3"
#include <bits/stdc++.h>
using namespace std;
#define lo long
const int lmax=1999999999;
const long long lmx=1999999999999999999;
long long a[100003];
long long n,dp[4004][4004];
int main(){std::ios::sync_with_stdio(false);
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
   for (int l = 0; l < n; l++)
        for (int i = 1; i + l <= n; i++)
            dp[i][i + l] = max (a[i] - dp[i + 1][i + l], a[i + l] - dp[i][i + l - 1]);
cout<<dp[1][n]<<endl;
}
/*

                   *         *
                  * *       * *
                 *   *     *   *
                *     *   *     *
               *       * *       *
               *        *        *
                *               *
                 *             *
                  *           *
                   *         *
                    *       *
                     *     *
                      *   *
                       * *
                        *



*/



