#include<bits/stdc++.h>
#define ll long long
#define N 400009
#define inf 1000000000
using namespace std;

int n,m,p,q,a[N],h[N],num[N];
bool ok(int lim){
	int i,j,x,sum=0; bool flag1=0,flag2=0;
	memset(num,0,sizeof(num));
	for (i=j=2; i<=m; i++){
		for (; j<=m && a[h[j]]-a[h[i]]<=lim; j++){
			x=h[j];
			if ((x>>1)!=(p>>1) && (x>>1)!=(q>>1)){
				if (!num[x>>1]) sum++; num[x>>1]++;
			}
			if (x==(p^1)) flag1=1;
			if (x==(q^1)) flag2=1;
		}
		if (flag1 && flag2 && sum==n-2) return 1;
		x=h[i];
		if ((x>>1)!=(p>>1) && (x>>1)!=(q>>1)){
			num[x>>1]--; if (!num[x>>1]) sum--;
		}
		if (x==(p^1)) flag1=0;
		if (x==(q^1)) flag2=0;
		
	}
	return 0;
}
bool cmp(int x,int y){ return a[x]<a[y]; }
int main(){
	scanf("%d",&n); m=n<<1|1;
	int i;
	for (i=p=q=2; i<=m; i++){
		scanf("%d",&a[i]);
		if (a[i]<a[p]) p=i; if (a[i]>a[q]) q=i;
	}
	if (p==q){ puts("0"); return 0; }
	int x=-inf,y=inf;
	for (i=1; i<=n; i++) if (i!=(p>>1) && i!=(q>>1)){
		if (a[i<<1]>a[i<<1|1]) swap(a[i<<1],a[i<<1|1]);
		x=max(x,a[i<<1]); y=min(y,a[i<<1|1]);
	}
	if ((p^q)!=1){
		x=max(x,a[q^1]); y=min(y,a[p^1]);
	}
	ll ans=(ll)(x-a[p])*(a[q]-y);
	if ((p^q)!=1){
		for (i=2; i<=m; i++) h[i]=i;
		sort(h+2,h+m+1,cmp);
		int l=0,r=a[q]-a[p],mid;
		while (l<r){
			mid=l+r>>1;
			if (ok(mid)) r=mid; else l=mid+1;
		}
		ans=min(ans,(ll)(a[q]-a[p])*l);
	}
	printf("%lld\n",ans);
	return 0;
}
