#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
#include<cmath>

using namespace std;

const int mod = 1e9+7;

long long power(long long x, long long n) {
	long long res = 1;
	while(n>0) {
		if(n&1) res = res*x % mod;
		x = x*x % mod;
		n >>= 1;
	}
	return res;
}

long long nums[10010][100];

int main() {
	char s[10010];
	long long d;
	scanf("%s%lld", s, &d);
	int n = strlen(s);
	int a[n+1];
	for(int i=0; i<n; i++) {
		a[i] = s[i]-'0';
	}

	nums[0][0] = 1;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=9; j++) {
			for(int x=0; x<d; x++) {
				nums[i][(x+j)%d] += nums[i-1][x];
			}
		}
		for(int x=0; x<d; x++) {
			nums[i][x] %= mod;
		}
	}
	long long ans = 0;
	int rem = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<a[i]; j++) {
			ans += nums[n-i-1][(10*d-(rem+j))%d];
		}
		rem = (rem+a[i])%d;
	}
	if(rem==0) ans++;
	ans = (ans+mod-1)%mod;
	printf("%lld\n", ans);
    return 0;
}