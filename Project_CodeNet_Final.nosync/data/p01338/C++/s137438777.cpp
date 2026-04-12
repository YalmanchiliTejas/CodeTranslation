#include <cstdio>
#include <cstring>
int n,tb[5][5],dp[4][1<<8],score[]={0,0,60,70,80};
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		for(int i=0;i<5;i++) for(int j=0;j<5;j++)
			scanf("%d",&tb[i][j]);
		memset(dp,0,sizeof(dp));
		for(int i=0;i<(1<<8);i++) for(int j=0;j<5;j++) {
			if(tb[0][j]) {
				int sc=tb[0][j];
				if(j>0)sc+=i>>2*j-2&3;
				if(j<4)sc+=i>>2*j&3;
				while(sc>4)sc-=4;
				dp[0][i]+=score[sc];
			}
		}
		for(int i=1;i<4;i++) for(int j=0;j<(1<<8);j++) for(int jj=0;jj<(1<<8);jj++) {
			int sum=dp[i-1][j];
			for(int k=0;k<5;k++) {
				if(tb[i][k]) {
					int sc=tb[i][k];
					if(k>0)sc+=(j>>2*k-2&3)+(jj>>2*k-2&3);
					if(k<4)sc+=(j>>2*k&3)+(jj>>2*k&3);
					while(sc>4)sc-=4;
					sum+=score[sc];
				}
			}
			if(dp[i][jj]<sum)dp[i][jj]=sum;
		}
		int ans=0;
		for(int i=0;i<(1<<8);i++) {
			int sum=dp[3][i];
			for(int j=0;j<5;j++) {
				if(tb[4][j]) {
					int sc=tb[4][j];
					if(j>0)sc+=i>>2*j-2&3;
					if(j<4)sc+=i>>2*j&3;
					while(sc>4)sc-=4;
					sum+=score[sc];
				}
			}
			if(ans<sum)ans=sum;
		}
		printf("%d\n",ans);
	}
}