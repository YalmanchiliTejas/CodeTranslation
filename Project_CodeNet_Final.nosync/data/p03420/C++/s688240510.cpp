#include<bits/stdc++.h>
using ll = int_fast64_t;

int main(){
	ll n, k;
	scanf("%ld %ld", &n, &k);
	
	if(k==0){
		printf("%ld\n", n*n);
		return 0;
	}

	ll ans = 0;
	for(ll i=k+1; i<=n; i++){
		ans += (n/i)*(i-k);
		if(n%i) ans += std::max(0l, (n%i)-k+1);
	}
	printf("%ld\n", ans);
	return 0;
}
