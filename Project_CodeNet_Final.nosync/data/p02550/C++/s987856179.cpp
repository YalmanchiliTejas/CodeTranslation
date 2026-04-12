#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
LL n,x,m,a[100005],cnt,sum[100005],mpd[100005];
bool vis[100005];
int main(){
	scanf("%lld %lld %lld",&n,&x,&m);
	LL now=x;
	while(!vis[now])
	{
		vis[now]=true;
		a[++cnt]=now;
		sum[cnt]=sum[cnt-1]+now;
		mpd[now]=cnt;
		now*=now;
		now%=m;
	}
	if(n<=cnt)	printf("%lld",sum[n]);
	else
	{
		LL ans=sum[cnt];
		LL beg=mpd[now];
		LL len=(cnt-beg+1);
		n-=cnt;
		LL dodo=n/len;
		ans+=dodo*(sum[cnt]-sum[beg-1]);
		n-=dodo*len;
		LL i=beg;
		while(n-->0)
		{
			ans+=a[i];
			++i;
		}
		printf("%lld",ans);
	}
	return 0;
}