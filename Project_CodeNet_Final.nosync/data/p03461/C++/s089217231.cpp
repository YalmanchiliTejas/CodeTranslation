#include<algorithm>
#include<cstring>
#include<cstdio>
#define LL long long
#define Re register int
using namespace std;
const int N=103,M=13;
int n,m,d[13][13],f[103][103];
inline void in(Re &x){
    int f=0;x=0;char c=getchar();
    while(c<'0'||c>'9')f|=c=='-',c=getchar();
    while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
    x=f?-x:x;
}
int main(){
//	freopen("123.txt","r",stdin);
	in(n),in(m);
	for(Re i=1;i<=n;++i)
		for(Re j=1;j<=m;++j)
			in(d[i][j]);
	for(Re i=0;i<=100;++i)
		for(Re j=0;j<=100;++j)
			for(Re x=1;x<=n;++x)
				for(Re y=1;y<=m;++y)
					f[i][j]=max(f[i][j],d[x][y]-i*x-j*y);
	for(Re x=1;x<=n;++x)
		for(Re y=1;y<=m;++y){
			Re dis=2e9;
			for(Re i=0;i<=100;++i)
				for(Re j=0;j<=100;++j)
					dis=min(dis,f[i][j]+i*x+j*y);
			if(dis!=d[x][y]){puts("Impossible");return 0;}
		}
	puts("Possible\n202 10401");
    for(Re i=1;i<=100;i++)printf("%d %d X\n",i,i+1);
    for(Re i=102;i<202;i++)printf("%d %d Y\n",i,i+1);
    for(Re i=0;i<=100;i++)
        for(Re j=0;j<=100;j++)
            printf("%d %d %d\n",i+1,202-j,f[i][j]);
    puts("1 202");
}