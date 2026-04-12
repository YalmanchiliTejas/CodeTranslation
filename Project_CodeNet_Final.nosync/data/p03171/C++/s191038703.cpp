#include <stdio.h>
const int N=3e3+10;
long long int max(long long int a,long long int b){return a>b?a:b;}
long long int min(long long int a,long long int b){return a>b?b:a;}
bool went[N][N];
int a[N];
long long int f[N][N];
long long int dp(int l,int r,int player){
	if(l>r)return 0;
	if(!went[l][r])return f[l][r];
	went[l][r]=false;
	if(player==1)return f[l][r]=min(dp(l+1,r,player^1)-a[l],dp(l,r-1,player^1)-a[r]);
	return f[l][r]=max(dp(l+1,r,player^1)+a[l],dp(l,r-1,player^1)+a[r]);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)went[i][j]=true;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	printf("%lld\n",dp(1,n,0));
}
