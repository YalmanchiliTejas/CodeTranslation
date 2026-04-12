#include<bits/stdc++.h>
#define ll long long
using namespace std;
void qmax(int &x,int y) {if (x<y) x=y;}
void qmin(int &x,int y) {if (x>y) x=y;}
inline int read()
{
	char s;
	int k=0,base=1;
	while((s=getchar())!='-'&&s!=EOF&&!(isdigit(s)));
	if(s==EOF)exit(0);
	if(s=='-')base=-1,s=getchar();
	while(isdigit(s)){k=k*10+(s^'0');s=getchar();}
	return k*base;
}
inline void write(int x)
{
	static char cnt,num[15];cnt=0;
	if (!x)
	{
		putchar('0');
		return;
	}
	for (;x;x/=10) num[++cnt]=x%10;
	for (;cnt;putchar(num[cnt--]+48));
}
int n,k,s;
ll ans,s1;
int main()
{
#ifdef ylx
	freopen("arc91b.in","r",stdin);
	freopen("arc91b.out","w",stdout);
#endif
	n=read();k=read();
	if (k==0)
	{
		ans=(ll)n*n;
		printf("%lld",ans);
		return 0;
	}
	for (int j=k+1;j<=n;j++)
	{
		s=n/j;
		s1=(j-k);
		ans+=(ll)s1*s;
		if (n%j>=k)
		{
			ans+=(ll)(n%j-k+1);
		}
	}
	cout<<ans;
	return 0;
}
