#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
using namespace std;
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
typedef long long LL;
LL n,a[55],sum;
inline void Swap(int &A,int &B){
	int t=A;
	A=B;
	B=t;
}
inline int stupid(){
	int cnt=0,xb,pos;
	while(a[0]>=n){
		a[0]-=n;
		for(xb=1;xb<n;xb++) a[xb]++;
		pos=0;
		while(pos<n-1 && a[pos]<a[pos+1]) {
			swap(a[pos],a[pos+1]);
			pos++;
		}
		cnt++;
	}
	return cnt;
}
inline LL getto(int pre,LL nn){
	LL opr=MIN(((LL)a[pre]/nn)-1,(a[pre]-(LL)nn)/(LL)(nn)+1);
	return MAX(0,opr);
}
int main(){
	scanf("%lld",&n);
	int xb,x2;
	for(xb=0;xb<n;xb++) {
		scanf("%lld",&a[xb]);
		sum+=a[xb];
	}
	sort(a,a+n);
	reverse(a,a+n);
	if(sum>=0 && sum<=100000){
		printf("%d",stupid());
		return 0;
	}
	LL cnt=0,pos;
	while(a[0]>=n && a[0]-a[n-1]>=n){
		LL rch=0;
		while(rch<n && a[0]-a[rch]<n) rch++;
		LL getv=getto(rch-1,n-rch+1);
		for(xb=0;xb<rch;xb++) a[xb]-=getv*(n-rch+1);
		for(xb=rch;xb<n;xb++) a[xb]+=getv*rch;
		sort(a,a+n);
		reverse(a,a+n);
		cnt+=getv*rch;
	}
	LL opr=a[n-1]-n-15LL;
	if(opr<=0) cnt+=(LL)stupid();
	else{
		cnt+=opr*n;
		for(xb=0;xb<n;xb++) a[xb]-=opr;
		cnt+=(LL)stupid();
	}
	printf("%lld",cnt);
	return 0;
}