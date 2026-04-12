#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
const int maxn=2000+10;
const int mod=1000000007;
int N,X;
long long D;
long long dp[maxn][maxn];
#define read Read
long long quick_pow(long long a, long long b) {
    long long ans = 1;
    a %= mod;
    while (b) {
        if (b % 2 == 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
long long C(long long n, long long m) {
    if (m > n)
        return 0;
    long long ans = 1;
    for (int i = 1; i <= m; i++) {
        long long a = (n + i - m ) % mod;
        long long b = i % mod;
        ans = ans * (a * quick_pow(b, mod - 2) % mod) % mod;
    }
    return ans;
}
long long lucas(long long n, long long m) {
    if (m == 0) return 1;
    return C(n % mod, m % mod) * lucas(n / mod, m / mod) % mod;
}
long long sum[maxn][maxn];
void add(int i, int j, long long v) {
    while (j <= N) {
        sum[i][j] = (sum[i][j] + v);
        if (sum[i][j] >= mod)
            sum[i][j] -= mod;
        j += (j) & (-j);
    }
}

long long read(int i, int j) {
    long long s = 0;
    while (j > 0) {
        s = (s + sum[i][j]);
        if (s >= mod)
            s -= mod;
        j -= (j) & (-j);
    }
    return s;
}
int main(){
	//init();
	while(scanf("%d%lld%d", &N,&D,&X)==3&&(N,D,X)){
		memset(dp,0,sizeof(dp));
		memset(sum,0,sizeof(sum));
		for(int j=1;j<X;++j){
			dp[1][j]=1;
			add(1,j,1);
		}
		for(int i=2;i<=N;++i){
			for(int j=i;j<=N;++j){
				dp[i][j]=(dp[i][j]+read(i-1,j-1)-read(i-1,max(i-2,j-X))+mod)%mod;
				add(i,j,dp[i][j]);
				/*for(int k=1;k<X&&k<=j&&(i-1)<=(j-k);++k){
					dp[i][j]+=dp[i-1][j-k];
					dp[i][j]%=mod;
				}*/
			}
		}
		long long ans=0;
		for(int i=1;i<=N&&i<=D;++i){
			ans=(ans+dp[i][N]*lucas(D,i)%mod)%mod;
		}
		printf("%lld\n", ans);
	}
		
    return 0;
}