//2018-03-11
//LZYeah
//
#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define Forr(i,a,b) for(register int i=a;i>=b;i--)
using namespace std;
inline void File()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
inline void read(int &x)
{
	int p=1;
	x=0;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')p=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}
	x*=p;
}
int n,k;
ll ans;
int main()
{
//	File();
	read(n),read(k);
	if(k==0){printf("%lld\n",1ll*n*n);return 0;}
	Forr(i,n,k+1)
	{
		int OmO=n/i;
		int yoy=n%i;
		ans+=1ll*OmO*(i-k);
		if(yoy>=k)ans+=1ll*(yoy-k+1);
//		cout<<i<<' '<<ans<<endl;
	}
	printf("%lld\n",ans);
	return 0;
}
