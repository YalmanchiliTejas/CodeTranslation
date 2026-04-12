#include <bits/stdc++.h>

using namespace std;

long long n,x,y,i,j,base,mid,top,ans;
long long a[1000];

int main() {
	scanf("%lld",&n);
	for (i=0 ; i<n ; i++) scanf("%lld",&a[i]);
	
	base = 0;
	top = 1000000000000000000LL;
	
	while (base != top) {
		mid = (base + top) / 2;
		long long maksimal = n - mid - 1;
		long long pengali = n + 1;
		
		ans = 0;
		for (i=0 ; i<n ; i++) {
			long long jarak = a[i] - maksimal;
			ans += max(0LL,(jarak + pengali - 1) / pengali);
		}
		
		//printf("%lld %lld -- %lld : %lld\n",base,top,mid,ans);
		
		if (ans <= mid) top = mid; else base = mid + 1;
	}
	//printf("%lld\n",top);
	
	for (i=top ; i >= max(0LL,top-10000) ; i--) {
		mid = i;
		long long maksimal = n - mid - 1;
		long long pengali = n + 1;
		
		ans = 0;
		for (j=0 ; j<n ; j++) {
			long long jarak = a[j] - maksimal;
			ans += max(0LL,(jarak + pengali - 1) / pengali);
		}
		if (ans <= mid) top = mid;
		
		//printf("%lld %lld -- %lld : %lld\n",base,top,mid,ans);
	}
	printf("%lld\n",top);
}