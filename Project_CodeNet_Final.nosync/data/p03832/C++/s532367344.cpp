#include<cstdio>
#include<cstring>
int N,A,B,C,D;
int c[1010][1010];
int w[1010][1010];
int d[2][1010];

#define mod 1000000007
int add(int x,int y){
	return (x+=y)<mod?x:x-mod;
}
int mul(int x,int y){
	return (int)((long long int)x*y%mod);
}
void addto(int&x,int y){
	x = add(x,y);
}
int main(){
	scanf("%d%d%d%d%d",&N,&A,&B,&C,&D);

	for(int i=0; i<=N; i++)for(int j=0; j<=i; j++)
		c[i][j] = j==0||j==i?1:add(c[i-1][j],c[i-1][j-1]);
	for(int i=A; i<=B; i++){
		w[i][0] = 1;
		for(int j=1; j<=D && i*j<=N; j++)
			w[i][j] = mul(w[i][j-1], c[i*j-1][i-1]);
	}

	d[0][0] = 1;bool f = false;
	for(int k=A; k<=B; k++,f=!f){
		memset(d[!f],0,sizeof(d[!f]));
		for(int i=0; i<=N; i++){
			addto(d[!f][i], d[f][i]);
			for(int j=C; j<=D && k*j+i<=N; j++){
				addto(d[!f][k*j+i], mul(d[f][i], mul(c[i+k*j][i], w[k][j])));
			}
		}
	}
	printf("%d\n",d[f][N]);
	return 0;
}
