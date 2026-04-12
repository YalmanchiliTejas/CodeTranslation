//Love and Freedom.
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
#define inf 20021225
#define N 200100
#define mdn 1000000007
using namespace std;
int read()
{
	int s=0,t=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')	t=-1; ch=getchar();}
	while(ch>='0' && ch<='9')	s=s*10+ch-'0',ch=getchar();
	return s*t;
}
int f[N],n,m,pre[2][N]; char ch[N];
void upd(int &x,int y){x+=x+y>=mdn?y-mdn:y;}
int query(int l,int r,int w){return !l?pre[w][r]:(pre[w][r]-pre[w][l-1]+mdn)%mdn;}
int main()
{
	n=read(),m=read(); scanf("%s",ch+1);
	char w=ch[1]; int s=0,mn=inf,fs=0;
	for(int i=1;i<=m;i++)
		if(ch[i]==w)	s++;
		else	mn=s&1?min(s,mn):mn,fs=!fs?s:fs,s=0;
	mn=min(fs+!(fs&1),mn); f[0]=1,pre[0][1]=pre[0][0]=1;
	int ans=0;
	if(s==m)
	{
		f[0]=1; pre[0][0]=1;
		for(int i=2;i<=n;i++)
			f[i]=query(0,i-2,0),pre[0][i]=(pre[0][i-1]+f[i])%mdn;
		for(int i=1;i<=n;i++)	upd(ans,1ll*(i+1)*f[n-i-1]%mdn);
		printf("%d\n",ans+1);
		return 0;
	}
	for(int i=2;i<=n;i++)
		f[i]=query(max(0,i-mn-1),i-2,i&1),
		pre[i&1][i]=(pre[i&1][i-1]+f[i])%mdn,
		pre[!(i&1)][i]=pre[!(i&1)][i-1];
	for(int i=1;i<=mn;i+=2)	upd(ans,1ll*(i+1)*f[n-i-1]%mdn);
	printf("%d\n",ans);
	return 0;
}