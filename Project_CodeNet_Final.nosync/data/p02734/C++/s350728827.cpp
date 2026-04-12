#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int modd=998244353;
const int maxn=3005;
int n,s,a[maxn];
ll dp[3005][3005],sum[3005][3005];
//以i结尾，和为j的子序列的起始点下标和
inline int read() {
	char ch = getchar();
	int x = 0, f = 1;
	while (ch < '0' || ch > '9') f = (ch == '-' ? -1 : 1), ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
	return x * f;
}
int main() {
	n=read(),s=read();
	for(int i=1; i<=n; i++) a[i]=read();
	for(int i=1; i<=n; i++) {
		dp[i][a[i]]+=i;
		for(int j=a[i]; j<=s; j++)
			(dp[i][j]+=sum[i-1][j-a[i]])%=modd;
		for(int j=1; j<=s; j++)
			sum[i][j]=(sum[i-1][j] +dp[i][j])%modd;
	}
	ll ans=0;
	for(int i=1; i<=n; i++)
		(ans+=dp[i][s]*(ll)(n-i+1))%=modd;
	cout<<ans;
	return 0;
}