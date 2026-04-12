#include<cstdio>
#include<algorithm>
#define MAX 1000007
#define INF 0x3f3f3f3f
#define NINF 0xc0c0c0c0 

using namespace std;
typedef long long ll;
ll arr[MAX],sum[MAX],dp[MAX];

int main(){
    ll n;
    scanf("%lld",&n);
    for(int i =1;i<=n;i++){
        scanf("%lld",&arr[i]);
        if(i>=2)sum[i]=sum[i-2]+arr[i];
        else sum[i]=arr[i];
    }
    for(int i = 2;i<=n;i++){
        if(i&1){
            dp[i] = max(dp[i-1],dp[i-2]+arr[i]);
        }else{
            dp[i] = max(sum[i-1],dp[i-2]+arr[i]);
        }
    }
    printf("%lld",dp[n]);
}