#include<bits/stdc++.h>
using namespace std;
int A,B,tot,d[15][15];
bool mp[205][205];
struct edge{int i,j,x;};
edge tg[15][15],e[23333];
int main(){
	scanf("%d%d",&A,&B);
	for (int i=1;i<=A;i++)
		for (int j=1;j<=B;j++){
			scanf("%d",&d[i][j]);
			tg[i][j].i=-1;
		}
	for (int i=0;i<=100;i++)
		for (int j=0;j<=100;j++)
			for (int x=0;x<=100;x++){
				bool fl=0;
				for (int k=1;k<=A&&!fl;k++)
					for (int l=1;l<=B&&!fl;l++)
						if (i*k+j*l+x<d[k][l])
							fl=1;
				if (fl) continue;
				for (int k=1;k<=A&&!fl;k++)
					for (int l=1;l<=B&&!fl;l++)
						if (i*k+j*l+x==d[k][l])
							tg[k][l]=(edge){i,j,x};
			}
	for (int i=1;i<=100;i++)
		e[++tot]=(edge){i,i+1,-1};
	for (int i=102;i<=201;i++)
		e[++tot]=(edge){i,i+1,-2};
	for (int i=1;i<=A;i++)
		for (int j=1;j<=B;j++){
			if (tg[i][j].i==-1){
				puts("Impossible");
				//printf("%d %d\n",i,j);
				return 0;
			}
			if (!mp[tg[i][j].i][tg[i][j].j])
				e[++tot]=(edge){1+tg[i][j].i,202-tg[i][j].j,tg[i][j].x};
			mp[tg[i][j].i][tg[i][j].j]=1;
		}
	puts("Possible");
	printf("%d %d\n",202,tot);
	for (int i=1;i<=tot;i++){
		printf("%d %d ",e[i].i,e[i].j);
		if (e[i].x==-1) printf("X\n");
		else if (e[i].x==-2) printf("Y\n");
		else printf("%d\n",e[i].x);
	}
	printf("1 202");
}