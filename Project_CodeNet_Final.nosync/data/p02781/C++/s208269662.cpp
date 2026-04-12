#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;

char str[105];

ll dp[105][4][2];

void solve()
{
    scanf("%s", str);
    int n=strlen(str);
    int K;
    scanf("%d", &K);

    dp[0][0][0]=1;
    int i,j,k;
    for(i=0; i<n; i++) {
        int tmp=str[i]-'0';
        for(j=0; j<=K; j++) {
            for(k=0; k<2; k++) {
                if(dp[i][j][k]) {
                    if(k==0) {
                        int j2=j+(tmp==0? 0: 1);
                        if(j2<=K) dp[i+1][j2][k]+=dp[i][j][k];

                        if(tmp>0) {
                            if(j+1<=K) dp[i+1][j+1][1]+=(tmp-1)*dp[i][j][k];
                            dp[i+1][j][1]+=dp[i][j][k];
                        }
                    }
                    else {
                        if(j+1<=K) dp[i+1][j+1][k]+=9*dp[i][j][k];
                        dp[i+1][j][k]+=dp[i][j][k];
                    }
                }
            }
        }
    }
    ll ans=0;
    for(k=0; k<2; k++) {
        ans+=dp[n][K][k];
    }
    //printf("%lld\n", ans/729);
    printf("%lld\n",ans);
    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T; scanf("%d", &T);
    while(T--) {
        solve();
    }
#endif
    return 0;
}
