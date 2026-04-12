#include<stdio.h>
#include<algorithm>
using namespace std;
int c[20];
int dp[20][110000];
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b),a){
		for(int i=0;i<a;i++)scanf("%d",c+i);
		int L=0;
		int R=110000;
		while(L+1<R){
			int M=(L+R)/2;
			for(int i=0;i<=a;i++)for(int j=0;j<=b;j++)
				dp[i][j]=99999999;
			dp[0][0]=0;
			for(int i=0;i<a;i++)for(int j=0;j<=b;j++){
				if(dp[i][j]>9999999)continue;
				if(dp[i][j]<M&&j+c[i]<=b)dp[i][j+c[i]]=min(dp[i][j+c[i]],dp[i][j]+1);
				dp[i+1][j]=0;
			}
			if(dp[a][b]<9999999){
				R=M;
			}else L=M;
		}
		printf("%d\n",R);
	}
}