#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 200005
using namespace std;
typedef long long ll;
struct P{
	int x,id;
}a[N<<1];
int n,sum[N],mx[N<<1],w[N][2];
ll ans=1e18;
bool cmp(P a,P b){
	return a.x<b.x;
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		w[i][0]=x;w[i][1]=y;
		a[i].x=x;a[i].id=i;
		a[i+n].x=y;a[i+n].id=i;
	}
	n<<=1;
	sort(a+1,a+n+1,cmp);
	if(a[1].id!=a[n].id){
		for(int i=2,p=1,j=0;i<n;i++){
			while(j+j<n&&p<n-1){
				p++;
				sum[a[p].id]++;
				if(sum[a[p].id]==1) j++;
			}
			if(j+j<n) break;
			ans=min(ans,1LL*(a[p].x-a[i].x)*(a[n].x-a[1].x));
			sum[a[i].id]--;
			if(sum[a[i].id]==0) j--;
		}
	}
	memset(sum,0,sizeof(sum));
	for(int i=n;i;i--){
		sum[a[i].id]++;
		mx[i]=max(mx[i+1],sum[a[i].id]);
	}
	memset(sum,0,sizeof(sum));
	for(int i=1,mn=0,t=0;i<n;i++){
		sum[a[i].id]++;
		if(sum[a[i].id]==2&&!t) mn=a[i].x,t=1;
		if(mx[i+1]==2) continue;
		ans=min(ans,1LL*(a[i].x-a[1].x)*(a[n].x-(t==0?a[i+1].x:mn)));
	}
	printf("%lld",ans);
	return 0;
}