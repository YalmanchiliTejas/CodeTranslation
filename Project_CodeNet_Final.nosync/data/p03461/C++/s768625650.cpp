#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define gt getchar()
#define ll long long
#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
typedef std::pair<int,int> P;
#define mk std::make_pair
#define fr first
#define sc second
inline int in()
{
	int k=0;char ch=gt;bool p=1;
	while(ch<'-')ch=gt;if(ch=='-')ch=gt,p=0;
	while(ch>'-')k=k*10+ch-'0',ch=gt;
	return p?k:-k;
}
const int N=105;
int f[N][N],d[N][N];
int main()
{
	int n=in(),m=in();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			d[i][j]=in();
	for(int i=0;i<=100;++i)
		for(int j=0;j<=100;++j)
			for(int a=1;a<=n;++a)
				for(int b=1;b<=m;++b)
					f[i][j]=std::max(f[i][j],d[a][b]-a*i-b*j);
	for(int a=1;a<=n;++a)
		for(int b=1;b<=m;++b)
		{
			int mi=1e9;
			for(int i=0;i<=100;++i)
				for(int j=0;j<=100;++j)
					mi=std::min(mi,f[i][j]+a*i+b*j);
			if(mi!=d[a][b])return puts("Impossible"),0;
		}
	puts("Possible\n202 10401");
	for(int i=1;i<=100;++i)printf("%d %d X\n",i,i+1);
	for(int i=1;i<=100;++i)printf("%d %d Y\n",i+101,i+102);
	for(int i=0;i<=100;++i)
		for(int j=0;j<=100;++j)
			printf("%d %d %d\n",i+1,202-j,f[i][j]);
	puts("1 202");
	return 0;
}
