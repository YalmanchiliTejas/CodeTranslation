#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN=2e5+10;
int N;
int arr[MAXN];

typedef long long int ll;

ll dp[MAXN][3];

int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%d",arr+i);

    dp[1][0]=0;
    dp[1][1]=arr[1];
    dp[0][0]=0;
    dp[2][0]=0;

    for(int i=0;i<=N;i++){
        for(int j=max(i/2-1,0);j<=(i+1)/2;j++){
            // printf("i=%d j=%d\n",i,j);
            if (i+2<=N) dp[i+2][(j+1)%3]=dp[i][j%3]+arr[i+2];
            if (i+1<=N) dp[i+1][j%3]=max(dp[i+1][j%3],dp[i][j%3]);
        }
    }

    printf("%lld\n",dp[N][(N/2)%3]);

    return 0;
}