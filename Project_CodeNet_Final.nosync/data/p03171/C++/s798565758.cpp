#include<cstdio>
#include<algorithm>
using namespace std;

#define i64 long long int
#define ran 3033

int n;
int a[ran];
i64 f[ran][ran];
bool visd[ran][ran];

i64 dp(int l, int r) {
	if (l>r || visd[l][r]) return f[l][r];
	
	i64 t = 0;
	if ((r-l)%2 == (n-1)%2)
		t = max(dp(l+1, r) + a[l], dp(l, r-1) + a[r]);
	else
		t = min(dp(l+1, r) - a[l], dp(l, r-1) - a[r]);
	
	visd[l][r] = true;
	f[l][r] = t;
	return t;
}

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	printf("%lld\n", dp(1, n));
	
	return 0;
}