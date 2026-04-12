#include<cstdio>

using namespace std;

int memo[11][1024];

int main(){
	int sw[1024];
	for(int i=0;i<1024;i++){
		sw[i]=0;
		if(i&1)		sw[i]^=3;
		for(int j=1;j<9;j++)	if(i&(1<<j))	sw[i]^=(7<<(j-1));
		if(i&512)	sw[i]^=768;
	}

	int t;	scanf("%d",&t);
	while(t--){
		int cell[10]={};
		for(int i=0;i<10;i++){
			cell[i]=0;
			for(int j=0,tmp;j<10;j++)	scanf("%d",&tmp),cell[i]|=(tmp<<(9-j));
		}

		for(int i=0;i<1024;i++)	memo[0][i]=0;
		for(int r=1;r<=10;r++){
			for(int i=0;i<1024;i++){
				memo[r][i]=-1;
				for(int b=0;b<1024;b++){
					if(memo[r-1][b]==-1)	continue;
					if((cell[r-1]^memo[r-1][b]^sw[b]^i)==0)	memo[r][i]=b;
				}
			}
		}

		int ans[10];
		for(int i=0,j=memo[10-i][0];i<10;i++,j=memo[10-i][j])	ans[i]=j;
		for(int i=9;i>=0;i--){
			for(int k=9;k>=0;k--)	printf("%s%d",(k==9?"":" "),(bool)(ans[i]&(1<<k)));
			puts("");
		}
	}

	return 0;
}