#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1LL<<50;
const int maxn=3010;
int n,a[maxn];
ll dp[maxn][maxn][2];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int len=1;len<=n;len++)
	for (int l=1,r;l+len-1<=n;l++) {
		r=l+len-1;
		dp[l][r][0]=max(dp[l+1][r][1]+a[l],dp[l][r-1][1]+a[r]);
		dp[l][r][1]=min(dp[l+1][r][0]-a[l],dp[l][r-1][0]-a[r]);
	}
	printf("%lld\n",dp[1][n][0]);
	return 0;
}