#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstdlib>
#define cmax(a,b) (a<(b)?a=(b),1:0)
#define cmin(a,b) (a>(b)?a=(b),1:0)
#define dmin(a,b) ((a)<(b)?(a):(b))
#define dmax(a,b) ((a)>(b)?(a):(b))
#define regsiter register
#define CL fclose(stdin),fclose(stdout)
namespace io
{
	int F()
	{
		int n=0,F=1;
		char ch;
		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		ch=='-'?F=0:n=ch-'0';
		while((ch=getchar())>='0'&&ch<='9')n=(n<<1)+(n<<3)+ch-'0';
		return F?n:-n;
	}
	long long G()
	{
		long long n=0,F=1;
		char ch;
		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		ch=='-'?F=0:n=ch-'0';
		while((ch=getchar())>='0'&&ch<='9')n=(n<<1)+(n<<3)+ch-'0';
		return F?n:-n;
	}
}
int m[666666];
int* a=m;
int op[111111],pop;
int main()
{
	int n=io::F();
	for(register int i=1;i<=n;++i)a[i]=io::F();
	int cnt=0;
	if(a[1]==n-1)a[n+1]=a[1],++a,op[++pop]=1;
	while(1)
	{
		if(cnt%n==0)
		{
			int fl=1;
			for(register int i=1;i<n;++i)if(a[i]>a[i+1])fl=0;
			if(fl)break;
		}
		else if(a[1]<a[n])std::swap(a[1],a[n]),op[++pop]=n-1;
		a[n+1]=a[1];
		++a;
		op[++pop]=1;
		++cnt;
	}
	printf("%d\n",pop);
	for(register int i=1;i<=pop;++i)printf("%d\n",op[i]);
	return 0;
}


