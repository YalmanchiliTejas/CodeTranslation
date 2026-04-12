#include <bits/stdc++.h>
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
int n,dp[2003][2003],a[6003],ans,tg,MX[2003],cur;
int A[100004],B[100004],C[100004],t;
void add(int x,int y,int z){A[t]=x,B[t]=y,C[t++]=z;}
int main(){
	cin>>n;
	for(int i=1;i<=3*n;i++)scanf("%d",&a[i]);
	memset(dp,-1,sizeof(dp));
	memset(MX,-1,sizeof(MX));
	dp[a[1]][a[2]]=dp[a[2]][a[1]]=MX[a[1]]=MX[a[2]]=cur=0;
	for(int i=3;i<3*n;i+=3){
		if(a[i]==a[i+1]&&a[i]==a[i+2]){tg++;continue;}
		t=0;
		if(a[i]>a[i+1])swap(a[i],a[i+1]);
		if(a[i+1]>a[i+2])swap(a[i+1],a[i+2]);
		if(a[i]>a[i+1])swap(a[i],a[i+1]);
		if(a[i]==a[i+1]||a[i+1]==a[i+2])for(int j=1;j<=n;j++){
			if(a[i]==a[i+1]){
				if(dp[j][a[i]]>=0)add(j,a[i+2],dp[j][a[i]]+1);
			}else if(dp[j][a[i+1]]>=0)add(j,a[i],dp[j][a[i+1]]+1);
		}
		if(dp[a[i]][a[i]]>=0)add(a[i+1],a[i+2],dp[a[i]][a[i]]+1);
		if(dp[a[i+1]][a[i+1]]>=0)add(a[i],a[i+2],dp[a[i+1]][a[i+1]]+1);
		if(dp[a[i+2]][a[i+2]]>=0)add(a[i],a[i+1],dp[a[i+2]][a[i+2]]+1);
		add(a[i],a[i+1],cur),add(a[i+1],a[i+2],cur),add(a[i],a[i+2],cur);
		for(int k=1;k<=n;k++)if(MX[k]>=0)add(a[i],k,MX[k]),add(a[i+1],k,MX[k]),add(a[i+2],k,MX[k]);
		for(int j=0;j<t;j++)if(dp[A[j]][B[j]]<C[j])
			dp[A[j]][B[j]]=dp[B[j]][A[j]]=C[j],MX[A[j]]=max(MX[A[j]],C[j]),MX[B[j]]=max(MX[B[j]],C[j]),cur=max(cur,C[j]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)ans=max(ans,dp[i][j]);
		if(dp[i][i]>=0)if(i==a[3*n])ans=max(ans,dp[i][i]+1);
	}
	printf("%d",ans+tg);
}