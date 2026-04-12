#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
#define M 200005
using namespace std;
int n,now,ans,A[M],B[M],c[M];
void add(int x,int d) {
	while(x) {
		c[x]=max(c[x],d);
		x-=lowbit(x);
	}
}
int sum(int x) {
	int s=0;
	while(x<=200000) {
		s=max(s,c[x]);
		x+=lowbit(x);
	}
	return s;
}
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++)scanf("%d",&A[i]),B[i]=A[i];
	sort(B+1,B+n+1);
	int num=unique(B+1,B+n+1)-B-1;
	for(int i=1; i<=n; i++)A[i]=lower_bound(B+1,B+num+1,A[i])-B;
	for(int i=1; i<=n; i++) {
		int now=sum(A[i])+1;
		add(A[i],now);
		ans=max(ans,now);
	}
	printf("%d",ans);
	return 0;
}