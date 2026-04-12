#include<bits/stdc++.h>
#define db double
#define ll long long
#define reg register
#define pb(x) push_back(x)
#define fup(i,x,y) for(reg int i=x;i<=y;++i)
#define fdw(i,x,y) for(reg int i=x;i>=y;--i)
using namespace std;
const int N=2e5+10;
ll a[N],ans=-1e18,n,f[N][2];
inline int read()
{
	int x=0,ff=1;
	char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-') ff=-1;ch=getchar();}
	while(isdigit(ch)) {x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*ff;
}
int main()
{
//	freopen("1.in","r",stdin);
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	memset(f,0xef,sizeof(f));
	f[1][1]=a[1];f[1][0]=0;
	f[2][1]=max(a[1],a[2]);
	for(int i=3;i<=n;++i)
	{
		if(i%2!=0)
		{
			f[i][0]=max(f[i-2][0]+a[i],max(f[i-2][1],f[i-1][1]));
			f[i][1]=f[i-2][1]+a[i];	
		}
		else f[i][1]=max(f[i-1][1],f[i-2][1]+a[i]);
	}
	if(n%2==0) cout<<f[n][1]<<endl;
	else       cout<<f[n][0]<<endl;
	return 0;
}

