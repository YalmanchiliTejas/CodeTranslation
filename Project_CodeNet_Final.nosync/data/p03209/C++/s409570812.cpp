#include<bits/stdc++.h>
using ll = int_fast64_t;

ll thick[51], patty[51];

ll recur(ll n, ll x){
	if(n==0 && x) return 1;

	if(x<=1) return 0;
	if(x<=1+thick[n-1]) return recur(n-1, x-1);
	if(x<=2+thick[n-1]*2) return 1 + patty[n-1] + recur(n-1, x-2-thick[n-1]);
	return patty[n];
}

int main(){
	thick[0] = patty[0] = 1;
	for(int i=0; i<50; i++){
		thick[i+1] = thick[i] * 2 + 3;
		patty[i+1] = patty[i] * 2 + 1;
	}

	ll n, x;
	scanf("%ld %ld", &n, &x);
	printf("%ld\n", recur(n, x));
	return 0;
}
