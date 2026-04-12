#include<cstdio>
#include<cctype>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn = 100 + 5;
const int mod = 1e9 + 7;

int qpow(int a,int k) { int ans = 1; for(;k > 0;k >>= 1,a = ((ll)a * a) % mod) if(k & 1) ans = ((ll)ans * a) % mod;return ans;}

int h[maxn] , w[maxn] , dp[maxn][maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",h + i) , w[i] = h[i];
	sort(w + 1,w + n + 1); int m = unique(w + 1,w + n + 1) - w - 1;
	for(int i = 1;i <= n;i++) h[i] = lower_bound(w + 1,w + m + 1,h[i]) - w;
	dp[0][0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = h[i] + 1;j <= h[i - 1];j++) dp[i][0] = (dp[i][0] + dp[i - 1][j] * 2 % mod) % mod;
		dp[i][0] = (dp[i][0] + dp[i - 1][0] * 2 % mod) % mod;
		for(int j = 1;j <= h[i];j++){
			dp[i][j] = (ll) dp[i - 1][j] * qpow(2,w[h[i]] - w[h[i - 1]]) % mod;
			if(h[i - 1] >= j) continue;
			if(j > 1) dp[i][j] = (dp[i][j] + (ll)dp[i - 1][0] * (qpow(2,w[j] - w[j - 1]) - 1) % mod * 2 % mod * qpow(2,w[h[i]] - w[j]) % mod) % mod;
			else dp[i][j] = (dp[i][j] + (ll)dp[i - 1][0] * (qpow(2,w[j]) - 2) % mod * qpow(2,w[h[i]] - w[j])) % mod;
		} 
	}
	int ans = 0;
	for(int i = 0;i <= m;i++) ans = (ans + dp[n][i]) % mod;
	printf("%d\n",ans);
	
} 