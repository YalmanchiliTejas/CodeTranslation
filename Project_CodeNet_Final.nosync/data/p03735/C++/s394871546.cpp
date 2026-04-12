#include<bits/stdc++.h>
#define maxn 201000
#define inf 1000000007
using namespace std;
int n,a[maxn],b[maxn],mx=-inf,mn=inf,omx,omn,c[maxn];
int comp(int x,int y){
	return a[x]<a[y];
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i],&b[i]),c[i]=i;
		if(a[i]>b[i])swap(a[i],b[i]);
		if(mx<b[i])mx=b[i],omx=a[i];
		if(mn>a[i])mn=a[i],omn=b[i];
	}
	int _mx=omx,_mn=omn;
	for(int i=1;i<=n;++i)
		_mx=max(_mx,a[i]),_mn=min(_mn,b[i]);
	long long ans=1ll*(mx-_mn)*(_mx-mn);
	sort(c+1,c+n+1,comp);
	int x=inf;
	for(int i=1;i<=n;++i)
		ans=min(ans,1ll*(mx-mn)*(_mx-min(a[c[i]],x))),x=min(b[c[i]],x),_mx=max(_mx,b[c[i]]);
	printf("%lld",ans);
}
 