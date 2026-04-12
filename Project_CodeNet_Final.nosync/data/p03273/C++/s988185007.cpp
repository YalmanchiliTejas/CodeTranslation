#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int N=100+50;
int n,m,visR[N],visC[N];
char a[N][N];

inline int read(){
	int x=0,f=1;char ch;
	for(ch=getchar();!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+ch-'0';
	return x*f;
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
	for(int i=1;i<=n;++i){
		visR[i]=1;
		for(int j=1;j<=m;++j)if(a[i][j]=='#'){
			visR[i]=0;break;
		}
	}
	for(int i=1;i<=m;++i){
		visC[i]=1;
		for(int j=1;j<=n;++j)if(a[j][i]=='#'){
			visC[i]=0;break;
		}
	}
	for(int i=1;i<=n;++i)if(!visR[i]){
		for(int j=1;j<=m;++j)if(!visC[j])putchar(a[i][j]);
		puts("");
	}
	return 0;
}