#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL n, m, i, j, k, a[55], c[55];
int main(){
	scanf("%lld%lld", &n, &k);
	a[0] = c[0] = 1;
	for(i=1; i<=n; i++){
		a[i] = a[i-1] * 2 + 1;
		c[i] = c[i-1] * 2 + 3;
	}
	while(k > 0){
		if(k >= c[n]){
			m += a[n], k = 0;
		}
		else if(k > c[n-1]){
			k -= c[n-1] + 1;
			m += a[n-1];
			if(k) m++, k--;
		}
		else k--;
		n--;
	}
	printf("%lld\n", m);
	return 0;
}