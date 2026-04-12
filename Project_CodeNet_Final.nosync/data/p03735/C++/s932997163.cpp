#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=4e5+10;
int n,x[N],sa[N],pos[N],Max,Min;
bool cmp(int a,int b){return x[a]<x[b];}
ll ans=1e18;
void add(int *cnt,int*num,int v,int d){
	num[cnt[v]]--;
	num[cnt[v]+=d]++;
}
void solve1(){//Min,Max属于一个集合的情况
	static int cnt[N],num[N];
	//cnt[i]表示(x[i],y[i])在当前区间中出现了几次
	//num[i]表示出现了i次的区间有几个
	num[0]=n;
	for (int l=1,r=0;l<=n+n;l++){
		while (num[0]&&r<n+n) add(cnt,num,pos[++r],1);
		if (!num[0]) ans=min(ans,1ll*(Max-Min)*(x[sa[r]]-x[sa[l]]));
		add(cnt,num,pos[l],-1);
	}
}
void solve2(){//Min,Max不在同一个集合的情况
	static int cnt1[N],num1[N],cnt2[N],num2[N];
	num1[0]=n;num2[0]=n;
	int l=0,r=n+n+1;
	while (num1[0]) add(cnt1,num1,pos[++l],1);
	while (num2[0]) add(cnt2,num2,pos[--r],1);
	ans=min(ans,1ll*(x[sa[l]]-Min)*(Max-x[sa[r]]));
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&x[i+n]);
	for (int i=1;i<=n+n;i++) sa[i]=i;
	sort(sa+1,sa+n+n+1,cmp);
	for (int i=1;i<=n+n;i++) pos[i]=(sa[i]>n?sa[i]-n:sa[i]);
	Min=x[sa[1]];Max=x[sa[n+n]];
	solve1();solve2();
	printf("%lld\n",ans);
	return 0;
}