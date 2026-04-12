#include <stdio.h>
#include <math.h>

int a[8],N;

int next(){

	/*
	13245の次は、13254
	13254の次は、13425
	15243の次は、15324
	35421の次は、41235
	右から見ていって、単調増加が崩れた最初の桁から右が変わる。
	最初の桁は、それよりの左で使われていないものの中でもとより大きいものに
	変わる。残りは、昇順に並ぶ。*/

	int i,j,p,b[8],c[8];

	for(i = N-1; i>0;i--){
		if(a[i-1]<a[i]){
			p = i-1;
			break;
		}
	}

	/*使った数字チェック*/
	for(i=0;i<N;i++){
		b[i] = 0;
	}
	for(i=0;i<p;i++){
		b[a[i]-1] = 1;
		c[i] = a[i];
	}

	/*c[p]を決める*/

	for(i=a[p];i<N;i++){
		if(b[i]==0){c[p] = i+1; b[i]=1; break;}
	}

	/*c[p+1]以降を決める*/
	for(i=p+1;i<N;i++){
		for(j=0;j<N;j++){
			if(b[j]==0){
				b[j]=1; c[i] = j+1; break;
			}
		}
	}

	for(i=0;i<N;i++){
		a[i] = c[i];
	}
	return 0;
}

int main() {
	int i,j,M,p[8][8],p1,p2,ans,pp;
	scanf("%d %d",&N,&M);

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			p[i][j] = 0;
		}
	}

	for(i=0;i<M;i++){
		scanf("%d %d",&p1,&p2);
		p[p1-1][p2-1] = 1;
		p[p2-1][p1-1] = 1;
	}
	
	for(i=0;i<N;i++){
		a[i] = i+1;
	}

	ans = 0;

	while(a[0]==1){
		pp = 1;
		for(i=0;i<N-1;i++){
			if(p[a[i]-1][a[i+1]-1] == 0){
				pp = 0;
			}
		}
		if(pp == 1){ans++;}
		next();
	}

	printf("%d\n",ans);

}
