#include <cstdio>
#include <algorithm>
#define reg register
#define min(_a,_b) (_a<_b?_a:_b)
#define max(_a,_b) (_a>_b?_a:_b)
#define reg register
struct node{
	int x,y;
}q[200002];
int R()
{
	reg int x=0;reg char ch=getchar_unlocked();
	for(;ch<48||ch>57;ch=getchar_unlocked());
	for(;ch>=48&&ch<=57;ch=getchar_unlocked()) x=x*10+ch-48;
	return x;
}
bool cmp(reg node i,reg node j)
{
	return i.x<j.x;
}
int main()
{
	reg int n=R(),i,max1=-1,max2=-1,min1=999999999,min2=999999999,k;
	reg long long ans,s;
	for(i=1;i<=n;++i) {
		q[i]=(node){R(),R()};
		if(q[i].x>q[i].y) std::swap(q[i].x,q[i].y);
		max1=max(max1,q[i].x),min1=min(min1,q[i].x);
		max2=max(max2,q[i].y),min2=min(min2,q[i].y);
	}
	ans=(long long)(max1-min1)*(max2-min2);
	std::sort(q+1,q+1+n,cmp);
	s=max2-min1;
	max1=q[n].x,min1=k=999999999;
	for(i=1;i<n;++i) {
		max1=max(max1,q[i].y),min1=min(min1,q[i].y);
		k=min(k,max1-min(min1,q[i+1].x));
	}
	printf("%lld",min(ans,s*k));
}