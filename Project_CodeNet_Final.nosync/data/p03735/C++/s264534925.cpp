#include <algorithm>
#include <cstdio>

const int N=200005,inf=1000000000;
int cnt[N];

struct P{
	int v,id;
}q[N*2];

bool cmp(P a,P b){return a.v<b.v;}

int main(){
	int n,max1=0,max2=0,min1=inf,min2=inf,tot=0;
	scanf("%d\n",&n);
	for (int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d\n",&x,&y);
		if (x<y) std::swap(x,y);
		max1=std::max(max1,x);
		max2=std::max(max2,y);
		min1=std::min(min1,x);
		min2=std::min(min2,y);
		q[++tot].v=x;q[tot].id=i;
		q[++tot].v=y;q[tot].id=i;
	}
	long long ans=1ll*(max1-min1)*(max2-min2);
	std::sort(q+1,q+tot+1,cmp);
	for (int i=1,j=1,k=0;i<=tot;i++){
		for (;j<=tot && k<n;j++) k+=!cnt[q[j].id]++;
		if (k<n) break;
		ans=std::min(ans,1ll*(max1-min2)*(q[j-1].v-q[i].v));
		k-=!--cnt[q[i].id];
	}
	printf("%lld\n",ans);
}