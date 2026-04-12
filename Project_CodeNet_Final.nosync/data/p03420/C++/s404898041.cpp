#include <algorithm>
#include   <cstring>
#include    <cstdio>
using namespace std;

typedef long long LL;
int n,m;
LL ans;

LL calc(int l,int r){
	return 1LL*(l+r)*(r-l+1)/2;
}

void solve(){
	ans=0;
	if(m==0){
		printf("%lld\n",1LL*n*n);
		return;
	}
	int last;
	int val=n-m;
	for(int i=m+1;i<=n;i=last+1){
		last=n/(n/i);
		//div
		ans+=1LL*(n/i)*calc(i-m,last-m);
		//mod
		int r=val/(n/i);
		if(r<i)continue;
		r=min(r,last);
		ans+=1LL*(r-i+1)*(val+1)-1LL*(n/i)*calc(i,r);
	}
	printf("%lld\n",ans);
}

int main(){
		scanf("%d%d",&n,&m);
		solve();
	return 0;
}