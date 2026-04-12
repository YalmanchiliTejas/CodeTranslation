#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
int n;
long long a[200005];
long long f[200005];
long long s[200005];

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++) {
		s[i]=(s[i-1]+a[i])%mod;
	}
	for(int i=1;i<=n;i++) {
		f[i]=(f[i-1]+(a[i]*s[i-1])%mod)%mod;
	}
	printf("%d",f[n]);
	return 0;
}