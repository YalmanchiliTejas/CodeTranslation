#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x;
	long long y;
};
node v[200010];long long n;long long sum,ans=1999999999,cnt;
long long a[200010],b[200010];long long maxn=-1,minn=1999999999;
long long minr=1999999999,minl=1999999999,maxl=-1,maxr=-1;
long long cmp(node a,node b)
{
	return a.x<b.x;
}
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	scanf("%lld%lld",&a[i],&b[i]);
	for(long long i=1;i<=n;i++)
	{
		if(a[i]>b[i])
		swap(a[i],b[i]);
		v[i].x=a[i];v[i].y=b[i];
		minl=min(a[i],minl);
		minr=min(b[i],minr);
		maxl=max(a[i],maxl);
		maxr=max(b[i],maxr);
	}
	sum=(maxl-minl)*(maxr-minr);
	minr=minl;
	sort(v+1,v+1+n,cmp);
	minn=maxn=v[1].y;
	for(long long i=2;i<=n;i++)
	{
		maxn=max(maxn,v[i].y);
		minn=min(minn,v[i].y);
		if(i!=n)
		ans=min(ans,max(maxn,v[n].x)-min(minn,v[i+1].x));
	}
	ans=ans*(maxr-minr);
	cnt=min(sum,ans);
	cout<<cnt;
	return 0;
} 