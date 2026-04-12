#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
typedef long long LL;
using namespace std;
int a[100005];
int main(){
	int n, p, q;
	LL ans;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	p = 1;
	q = n;
	ans = abs(a[1] - a[n]);
	for(int i = 2;i <= n / 2;i++){
		ans += (LL)abs(a[p] - a[n - i + 1]) + (LL)abs(a[q] - a[i]);
		p++;
		q--;
	}
	if(n & 1){//n是奇数
		ans += (LL) max(abs(a[n / 2 + 1] - a[q]), abs(a[n / 2 + 1] - a[p]));
	}
	printf("%lld\n", ans);
}