#include<cstdio>
#include<cstring>

int fie[16][16];
int n;

int main(void){
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		memset(fie,0,sizeof(fie));
		int x=n/2,y=n/2+1;
		int cnt=1;
		while(cnt<=n*n){
			while(1){
				if(x>=0 && x<n && y>=0 && y<n){
					if(fie[x][y]==0)break;
					if(fie[x][y]!=0)x--,y++;
				}else{
					if(x<0)x=n-1;
					if(x>=n)x=0;
					if(y>=n)y=0;
				}
			}
			fie[x][y]=cnt;
			x++,y++;
			cnt++;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)printf("%4d",fie[j][i]);
			printf("\n");
		}
	}
	return 0;
}