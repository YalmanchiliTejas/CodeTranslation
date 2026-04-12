#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=400005,INF=1e9;
int a[N],g[N],Max,Min,f[N],ans,n;
void solve2(){
	int Max1=a[Max],Min1=a[Max],Max2=a[Min],Min2=a[Min];
	int flag1=(Max+1)/2,flag2=(Min+1)/2;
	for (int i=1;i<=n;i++){
		if (i!=flag1&&i!=flag2){
			Min1=min(Min1,a[i*2-1]);
			Max2=max(Max2,a[i*2]);
		}
		if (i==flag1&&i!=flag2)Max2=max(Max2,a[i*2]);
		if (i!=flag1&&i==flag2)Min1=min(Min1,a[i*2-1]);
	}
	ans=min(ans,(Max1-Min1)*(Max2-Min2));
}
int cmp(int x,int y){
	return a[x*2]<a[y*2];
}
void solve1(){
	int p1=-1e9,p2=1e9,val=a[Max]-a[Min];
	int tot=0,flag1=(Max+1)/2,flag2=(Min+1)/2;
	for (int i=1;i<=n;i++){
		if (i==flag1)p1=max(p1,a[i*2]),p2=min(p2,a[i*2]);
		else if (i==flag2)p2=min(p2,a[i*2-1]),p1=max(p1,a[i*2-1]);
		else f[++tot]=i;
	}
	sort(f+1,f+tot+1,cmp);
	g[tot+1]=1e9;
	int now=-1e9,now2=1e9;
	for (int i=1;i<=tot+1;i++){
		ans=min(ans,val*(max(p1,max(i==tot+1?0:a[f[tot]*2],now))-min(p2,min(i==tot+1?1000000000:a[f[i]*2],now2))));
		if (i!=tot+1)now=max(now,a[f[i]*2-1]),now2=min(now2,a[f[i]*2-1]);
	}
}
signed main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i*2-1],&a[i*2]);
		if (a[i*2-1]<a[i*2])swap(a[i*2-1],a[i*2]);
	}
	Max=1,Min=2;
	for (int i=3;i<=n*2;i++){
		if (a[i]>a[Max])Max=i;
		if (a[i]<a[Min])Min=i;
	}
	ans=1e18;
	if ((Max-1)/2!=(Min-1)/2)solve1();
	solve2();
	printf("%lld\n",ans);
	return 0;
}
