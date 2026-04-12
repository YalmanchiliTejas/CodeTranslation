#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=1e4+10;
const int M=1e2+10;
const int mod=1e9+7;
int n,a[N],d,dp[2][M][2],cur,ans;char s[N];
inline void Add(int &x,int y){x+=y;x-=x>=mod? mod:0;}
inline int MOD(int x,int y){x+=y;x-=x>=mod? mod:0;return x;}
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	for(register int i=1;i<=n;i++)a[i]=s[i]-'0';
	scanf("%d",&d);dp[cur][0][1]=1;
	for(register int i=1;i<=n;i++){
		cur^=1;memset(dp[cur],0,sizeof(dp[cur]));
		for(register int j=0;j<=d;j++){
			for(register int p=0;p<=9;p++)
				Add(dp[cur][j][0],dp[cur^1][(j-p+d*9)%d][0]);
			for(register int p=0;p<a[i];p++)
				Add(dp[cur][j][0],dp[cur^1][(j-p+d*9)%d][1]);
			Add(dp[cur][j][1],dp[cur^1][(j-a[i]+d*9)%d][1]);
		}
	}
	printf("%d\n",MOD(MOD(dp[cur][0][1],dp[cur][0][0]),mod-1));
	return 0;
}