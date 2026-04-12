#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10005,M=998244353;
char s1[N],s2[N];
int dp[N][N/2],A,B;
signed main(){
	scanf("%s%s",s1+1,s2+1);
	int n=strlen(s1+1);
	for (int i=1;i<=n;i++)
		if (s1[i]=='1'&&s2[i]=='1')A++;
		else if (s1[i]=='1'&&s2[i]=='0')B++;
	dp[0][0]=1;
	for (int i=0;i<=A;i++)
		for (int j=0;j<=B;j++){
			if (i==0&&j==0)continue;
			if (i)(dp[i][j]+=dp[i-1][j]*i*j)%=M;
			if (j)(dp[i][j]+=dp[i][j-1]*j*j)%=M;
		}
	int ans=0,s=1;
	for (int i=0;i<=A;i++)(ans+=dp[A-i][B]*s)%=M,(s*=(A-i)*(A+B-i)%M)%=M;
	printf("%lld\n",ans);
}
