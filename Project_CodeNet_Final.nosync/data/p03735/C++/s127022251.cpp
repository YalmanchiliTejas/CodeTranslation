#include<bits/stdc++.h>
#define iid dqy[i].id
#define hh dqy[head].id^1
#define tt dqy[tail].id^1
using namespace std;
const int nn=4e5+10;
int p[nn];
long long s[nn];
struct orz{
	long long v;
	int id;
}dqy[nn];
bool cmp(orz a,orz b){return a.v<b.v;}
int main(){
	int n;
	scanf("%d",&n);
	int n2=n<<1;
	if(n==1)return putchar('0'),0;
	for(int i=1,a,b;i<=n;i++){
		a=(i<<1)-2,b=a+1;
		scanf("%lld%lld",s+a,s+b);
		dqy[a].v=s[a],dqy[a].id=a;
		dqy[b].v=s[b],dqy[b].id=b;
	}sort(dqy,dqy+n2,cmp);
	for(int i=0;i<n2;i++)p[iid]=i;
	long long maxs=0,minb=INT_MAX,lb=dqy[0].v,ub=dqy[n2-1].v;
	for(int i=n2-2;i;i--){
		if(dqy[i].v<=s[iid^1])maxs=max(maxs,dqy[i].v);
		if(dqy[i].v>=s[iid^1])minb=min(minb,dqy[i].v);
	}long long ans=(maxs-lb)*(ub-minb);
	if((dqy[0].id^1)!=(dqy[n2-1].id)&&ans!=0){
		int head=1,tail=0,num=0;
		for(;num<n;){
			tail++;
			if(p[tt]<1||tail<p[tt])num++;
		}while(head<=p[hh]&&p[hh]<=tail)head++;
		long long di=dqy[tail].v-dqy[head].v;
		while(true){
			head++;
			while(head<=p[hh]&&p[hh]<=tail)head++;
			for(tail++;head<=p[tt]&&p[tt]<=tail&&tail<n2-1;tail++);
			if(tail==n2-1)break;
			di=min(di,dqy[tail].v-dqy[head].v);
		}ans=min(ans,di*(dqy[n2-1].v-dqy[0].v));
	}printf("%lld",ans);
	return 0;
}