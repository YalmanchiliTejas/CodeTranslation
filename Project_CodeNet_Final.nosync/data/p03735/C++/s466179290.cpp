#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int a[maxn],b[maxn],v[maxn<<1],p[maxn<<1],pos[maxn<<1],t[maxn],Min=1e9,Max,Mi=1e9,Mx,ma,mb,m,n;
int cmp(int a,int b) {
	return v[a]<v[b];
}
int main() {
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",a+i,b+i);
		if(a[i]>b[i])swap(a[i],b[i]);
		if(Min>a[i])Min=a[ma=i];
		if(Max<b[i])Max=b[mb=i];
		Mi=min(Mi,b[i]);
		Mx=max(Mx,a[i]);
	}
	ans=1ll*(Max-Mi)*(Mx-Min);
	if(ma==mb) {
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(ma!=i&&mb!=i) {
			p[++m]=i;
			v[m]=a[i];
			p[++m]=i;
			v[m]=b[i];
		}
	for(int i=1;i<=m;i++)pos[i]=i;
	sort(pos+1,pos+1+m,cmp);
	for(int i=1,j=0,cnt=0;i<=m;i++) {
		while(j<m&&cnt<n-2) {
			if(!t[p[pos[++j]]])cnt++;
			t[p[pos[j]]]++;
		}
		Mi=min(v[pos[i]],min(b[ma],a[mb]));
		Mx=max(v[pos[j]],max(b[ma],a[mb]));
		if(cnt>=n-2)ans=min(ans,1ll*(Max-Min)*(Mx-Mi));
		t[p[pos[i]]]--;
		if(!t[p[pos[i]]])cnt--;
	}
	printf("%lld\n",ans);
	return 0;
}