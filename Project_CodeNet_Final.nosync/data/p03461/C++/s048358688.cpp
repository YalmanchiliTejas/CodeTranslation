#include<stdio.h>
const int inf=2147483647,mx=100;
void fmax(int&a,int b){
	if(b>a)a=b;
}
void fmin(int&a,int b){
	if(b<a)a=b;
}
int d[20][20],f[110][110];
int main(){
	int A,B,i,j,k,l,t;
	scanf("%d%d",&A,&B);
	for(i=1;i<=A;i++){
		for(j=1;j<=B;j++)scanf("%d",d[i]+j);
	}
	for(i=0;i<=mx;i++){
		for(j=0;j<=mx;j++){
			t=0;
			for(k=1;k<=A;k++){
				for(l=1;l<=B;l++)fmax(t,d[k][l]-i*k-j*l);
			}
			f[i][j]=t;
		}
	}
	for(i=1;i<=A;i++){
		for(j=1;j<=B;j++){
			t=inf;
			for(k=0;k<=mx;k++){
				for(l=0;l<=mx;l++)fmin(t,i*k+j*l+f[k][l]);
			}
			if(t!=d[i][j]){
				puts("Impossible");
				return 0;
			}
		}
	}
	printf("Possible\n%d %d\n",mx*2+2,mx*2+(mx+1)*(mx+1));
	for(i=1;i<=mx;i++)printf("%d %d X\n",i,i+1);
	for(i=mx+2;i<=2*mx+1;i++)printf("%d %d Y\n",i,i+1);
	for(i=0;i<=mx;i++){
		for(j=0;j<=mx;j++)printf("%d %d %d\n",1+i,2*mx+2-j,f[i][j]);
	}
	printf("%d %d",1,mx*2+2);
}