#include <bits/stdc++.h>

using namespace std;

long long a[55], s;
int n;

int main(){
//	freopen("input.inp", "r", stdin);
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i) scanf("%lld",&a[i]), s += a[i];
	for(long long k = max(0ll, s - n * (n - 1)); k <= s; ++k){
		long long op = 0;
		for(int i = 1; i <= n; ++i){
			op += (a[i] + k + 1) / (n + 1); 
		}
		if (op == k){
			printf("%lld",k);
			return 0;
		}
	}
	return 0; 
}