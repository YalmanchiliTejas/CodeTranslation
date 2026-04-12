#include<cstdio>

int main() {
	int n; scanf("%d", &n);
	
	int ma = 0, ans = 0;
	for(int i=1;i<=n;i++) {
		int x; scanf("%d", &x);
		if(x>=ma) {
			ans++;
			ma = x;
		}
	}
	printf("%d\n", ans);
	
	return 0;
}