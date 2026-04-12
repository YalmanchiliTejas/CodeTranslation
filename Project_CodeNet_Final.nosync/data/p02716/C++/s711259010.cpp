#include<stdio.h>
#include<algorithm>
using namespace std;
long long dp[200001];//到第i个数取到i/2个数的最大值
long long sum[200001];//隔一个选一个的和到第i个位置的和为多少
int a[200001];
int main(){
    int n;
    int len = 1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i] = (i>1?sum[i-2]:0)+a[i];
    }
    for(int i=2;i<=n;i++){
        if(i%2==0){
            dp[i] = max(dp[i-2]+a[i],sum[i-1]);
        }else{
            dp[i] = max(dp[i-2]+a[i],dp[i-1]);
        }
    }
    printf("%lld\n",dp[n]);
    return 0;
}
