#include<bits/stdc++.h>

using namespace std;
int n,a[202020];
const int mod = 1e9+7;
long long sum = 0;
int main() {
scanf("%d",&n);
for (int i = 1;i <= n; i++) {
	scanf("%d",&a[i]);
	sum += a[i];
}
	sum %= mod;
	sum *= sum;
	sum %= mod;
	for (int i = 1;i <= n; i++) {
		sum -= (long long)a[i]*a[i];
		sum %= mod;
	}
	sum += mod;
	sum %= mod;
	sum *= (mod+1)/2;
	sum %= mod;
	printf("%lld\n",sum);
	return 0;
}
/*
5
6 14 15 7 12 16 5 4 11 9 3 10 8 2 13 1
4
1 2 3 4 5 6 7 8
*/