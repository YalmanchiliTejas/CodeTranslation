#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
const ll INF=(1e16);
int n,t;
ll a[maxn],dp[maxn][20],ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=0;i<=n;i++)
	for (int j=0;j<19;j++) dp[i][j]=-INF;
	dp[0][0]=0;
	ans=-INF;
	int R;
	for (int i=1;i<=n;i++) {
		for (int j=0;j<=10;j++) {
			dp[i][j]=-INF;
			if ((i+1)/2-j<=0) continue;
			R=i-1;
			if (i==1) R=1;
			for (int k=max(0,i-10);k<R;k++) {
				t=(k+1)/2-((i+1)/2-j-1);
				//if (i==1&&j==0) printf("%d %d %lld\n",k,t,dp[k][t]);
				if (0<=t&&t<=10) {
					if (dp[k][t]!=-INF) {
						dp[i][j]=max(dp[i][j],dp[k][t]+a[i]);
					}
				}
			}
			//printf("%d %d %d %lld\n",i,j,(i+1)/2-j,dp[i][j]);
			if ((i+1)/2-j==n/2) ans=max(ans,dp[i][j]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/
