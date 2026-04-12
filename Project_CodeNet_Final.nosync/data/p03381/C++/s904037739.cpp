#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;
int a[N],b[N];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(a+1,a+n+1);
	int t=a[n/2];
	for(int i=1;i<=n;i++) {
		if(b[i]<=t) printf("%d\n",a[n/2+1]);
		else printf("%d\n",t);
	}
	return 0;
}