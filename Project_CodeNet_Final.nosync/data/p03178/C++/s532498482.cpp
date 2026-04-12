#include<cstdio>
#include<cstring>
const int L=10003,M=1e9+7;
inline int Mod(int a){return a<M?a:a-M;}
int d[L],l,m,f[L][103],s;char t[L];
signed main(){
	scanf("%s%d",t,&m);
	l=strlen(t);
	for(int i=1;i<=l;i++)d[i]=t[i-1]-48;
	for(int i=1;i<=l;i++){
	  for(int k=0;k<10;k++){
		for(int j=0;j<m;j++)
		  f[i][(j+k)%m]=Mod(f[i][(j+k)%m]+f[i-1][j]);
		if(k<d[i])f[i][(s+k)%m]=Mod(f[i][(s+k)%m]+1);
	  }
	  s=(s+d[i])%m;
	}
	printf("%d",(f[l][0]+(!s)-1+M)%M);
	return 0;
}