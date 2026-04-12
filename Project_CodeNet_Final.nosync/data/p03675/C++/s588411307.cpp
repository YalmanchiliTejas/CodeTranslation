#include <bits/stdc++.h>
using namespace std;
#define mem(ar,value) memset(ar,value,sizeof(ar))
#define all(x) x.begin(),x.end()
#define len(s) (int)s.size()
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define mod 1e9+7
#define limit 200005
#define READ freopen("input.txt","r",stdin)
#define WRITE freopen("output.txt","w",stdout)
#define d1(x) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
#define d2(x,y) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
#define d3(x,y,z) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z;
#define GG {printf("-1"); return 0;}
#define inf 1e9*2
#define y1 asdas
#define ll long long
#define writesize(a) printf("%d\n",len(a));
#define writeall(a) for(int i=0;i<len(a);i++) printf("%d ",a[i]);
int n,ar[limit],t=1,d[limit],mx,mn=1,k=1;
pair<int,int> ans[limit];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&ar[i]);
	}
	mx=n;
	for(int i=n;i>=1;i--,k++)
	{
		d[i]=t;
		if(k%2) mn++;
		else mx--;
		if(k%2) t=mx;
		else t=mn; 
	}
	for(int i=1;i<=n;i++)
	{
		ans[i]=mp(d[i],ar[i]);
	}
	sort(ans+1,ans+n+1);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",ans[i].sc);
	}
}

