//
#include<cstdio>
using namespace std;
const int N=300005;
int a[N],v[N],n,next[2][N],tag[N],fr,end,cnt;

void solve()
{
	if(cnt==0)	
		v[++cnt]=a[1];
	fr=end=1;
	for(int i=2;i<=n;++i)
	{
		v[++cnt]=a[i];		
		int t=0;
		if(next[0][end]!=0)	t=1;
		next[t][end]=cnt;
		next[!t][cnt]=end;
		int tt=fr;
		fr=cnt,end=tt;
	}
}	

int main()
{
//	freopen("1.txt","r",stdin);
//	freopen("11.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	solve();
	int t=0;
	if(next[1][fr])	t=1;	
	for(int i=fr;i!=end;i=next[t][i])
		printf("%d ",v[i]);
	printf("%d",v[end]);
	return 0;
}
		