#include<cmath>
#include<cstdio>
#include<cassert>
#include<cstring>
#include<algorithm>
#define MN 51
#define Cx 0.03
#define Cy 0.03
#define eps 1e-7
using namespace std;

int read_p,read_ca;
inline int read(){
    read_p=0;read_ca=getchar();
    while(read_ca<'0'||read_ca>'9') read_ca=getchar();
    while(read_ca>='0'&&read_ca<='9') read_p=read_p*10+read_ca-48,read_ca=getchar();
    return read_p;
}
int n,m,map[10][10],dp[10][1<<10],a,b,mmh=0;
int main(){
	register int i,j,k;
	n=read();m=read();
	for (i=1;i<=m;i++) scanf("%d%d",&a,&b),map[a][b]=map[b][a]=1;
	dp[1][1]=1;
	for (i=1;i<(1<<n);i++){
		for (j=1;j<=n;j++)
		if (dp[j][i])
		for (k=1;k<=n;k++)
		if (map[j][k]&&!((i>>(k-1))&1)) dp[k][i|(1<<(k-1))]+=dp[j][i];
	}
	for (i=1;i<=n;i++) mmh+=dp[i][(1<<n)-1];
	printf("%d\n",mmh);
}