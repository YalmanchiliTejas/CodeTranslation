#include <stdio.h>
#include <algorithm>
#define SIZE 3005
long long int dp[SIZE][SIZE], a[SIZE];

  int main(void) {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++) scanf("%lld",&a[i]);

        for(int l=n; l>=1; l--) {
                for(int r=l; r<=n; r++) {
                        if(l==r) dp[l][r] = a[l];
                        else dp[l][r] = std::max(a[l]-dp[l+1][r], a[r]-dp[l][r-1]);
                }
        }

        printf("%lld", dp[1][n]);
        return 0;
  }






