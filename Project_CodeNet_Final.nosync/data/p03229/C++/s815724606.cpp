#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define LL long long
#define RG register
using namespace std;
const int N=1e5+10;
int n; LL a[N];
inline LL read(){
	char ch=getchar(); LL x=0, f=1;
	while(ch<'0' || ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	if(n%2==0)
	{
		LL tt=-a[n/2];
		for(int i=1;i<=n/2;i++) tt+=2*a[i];
		tt=-tt;
		for(int i=n/2+1;i<=n;i++) tt+=2*a[i];
		tt-=a[n/2+1];
		printf("%lld\n",tt);  
	}
	else {
		LL tt1=0,tt2=0;
		for(int i=1;i<=n/2;i++) tt1+=2*a[i];
		tt1=-tt1;
		for(int i=n/2+1;i<=n;i++) tt1+=2*a[i];
		tt1-=a[n/2+1]; tt1-=a[n/2+2];
		
		for(int i=1;i<=n/2+1;i++) tt2+=2*a[i];
		tt2-=a[n/2+1]; tt2-=a[n/2];
		tt2=-tt2;
		for(int i=n/2+2;i<=n;i++) tt2+=2*a[i];
		printf("%lld\n",max(tt1,tt2));
	}
//	fclose(stdin); fclose(stdout);
	return 0;
}
