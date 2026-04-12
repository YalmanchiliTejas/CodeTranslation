#include <cstdio>
#include <algorithm>

using std::max;

int n,k;

inline int bin_chop(int l,int r,int a){
	int mid,div=a/l;
	while(l<=r){
		mid=l+r>>1;
		if(a-k>=mid*div) l=mid+1;
		else r=mid-1;
	}
	return r;
}

inline int solve(int n){
	int ret=0;
	for(int l=1,r;l<=n;l=r+1){
		r=n/(n/l);
		if(r>k) ret+=bin_chop(max(l,k),r,n)-l+1;
	}
	return ret;
}

int main(){
	scanf("%d%d",&n,&k);
	if(k==0) printf("%lld",(long long)n*n);
	else{
		long long ans=0;
		for(int i=k+1,cnt,r;i<=n;++i){
			cnt=n/i,r=n%i;
			ans+=(long long)cnt*(i-1-k+1);
			if(r>=k) ans+=r-k+1;
		}
		printf("%lld",ans);
	}
/*	for(int i=1;i<=n;++i)
		ans+=solve(i);
	for(int i=k;i<n;++i)
		ans+=n-(i+1)+1;
*/
	return 0;
}