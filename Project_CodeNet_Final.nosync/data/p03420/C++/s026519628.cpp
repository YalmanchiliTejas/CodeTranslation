#include <bits/stdc++.h>

using namespace std;

int n, k;

int main(){
	scanf("%d%d", &n, &k);
	
	long long res = 0;
	
	for(int i = k + 1; i <= n; i++){
		int mx = floor(n / i);
		int lt = n % i;
		
		res += 1LL * mx * (i - k);
		if(k == 0)
		res--;
		
		res += max(0, lt - k + 1);
	}
	
	printf("%lld\n", res);
}
