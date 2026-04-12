#include <bits/stdc++.h>
#define LL long long
using namespace std;
int n; LL K,a[100],x,w;
int main(){
	scanf("%d",&n); K=n-1;
	for (int i=1;i<=n;++i) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	if (a[n]<=K) {puts("0"); return 0;}
	while (a[1]<K){
		a[n]-=n+1; --K; sort(a+1,a+n+1);
		if (a[n]<=K) {printf("%lld\n",-K-1+n); return 0;}
	}
	w=0;
	for (int i=1;i<=n;++i) w+=a[i]; w-=n*K;
	for (;;++w){
		x=0;
		for (int i=1;i<=n;++i) x+=(a[i]-K+w+n)/(n+1);
		if (x==w) {printf("%lld\n",w+n-1-K); return 0;}
	}
	return 0;
}