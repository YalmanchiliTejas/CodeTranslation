#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MOD = 1000000007;

int n, a[MAXN];

int main(){
	scanf("%d", &n);
	
	long long sum = 0, res = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		
		res = (res + a[i] * sum) % MOD;
		sum = (sum + a[i]) % MOD;
	}
	printf("%lld\n", res);
	
	return 0;
}
