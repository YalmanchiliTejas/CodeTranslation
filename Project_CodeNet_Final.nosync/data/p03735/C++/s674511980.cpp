// luogu-judger-enable-o2
#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N=2*1e5+5,inf=1e9+5;;
int n;
LL A,B=inf,_A,_B=inf,ans;
int in[N],ou[N],cnt;
struct card {LL val,bag;} b[N<<1];
bool cmp(card u,card v)
{
	return u.val<v.val;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld%lld",&b[i*2-1].val,&b[i*2].val);
		b[i*2-1].bag=b[2*i].bag=i;
		if(b[i*2-1].val>b[i*2].val) swap(b[i*2-1],b[i*2]);
		A=max(b[i*2].val,A),B=min(b[i*2].val,B);
		_A=max(b[i*2-1].val,_A),_B=min(b[i*2-1].val,_B);
	}
	ans=(A-B)*(_A-_B);
	//cout<<ans<<" "<<A-_B<<endl;
	sort(b+1,b+n*2+1,cmp);
	//for(int i=1;i<=n<<1;++i) cout<<b[i].val<<" "<<b[i].bag<<endl;
	int l=2,r=2;
	while(r<=n*2)
	{
		while(cnt<n && r<=n*2) cnt+=(in[b[r].bag]==0),++in[b[r++].bag];
		if(r>2*n) break;
		while(in[b[l].bag]==2) --in[b[l].bag],++ou[b[l++].bag];
		ans=min(ans,(b[r-1].val-b[l].val)*(A-_B));
		//cout<<l<<" "<<r<<" "<<b[l].val<<" "<<b[r].val<<endl;
		if(ou[b[l].bag]==1) break;
		++ou[b[l].bag],--in[b[l].bag],++l,--cnt;
	}
	printf("%lld",ans);
	return 0;
}