#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL;
int n, pos;
LL a[55], k;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		if(a[pos] < a[i]){
			pos = i;
		}
	}
	while(a[pos] >= n) {
		LL tmp = a[pos] / n;
		a[pos] %= n;
		for(int i = 1; i <= n; i++){
			if(pos != i)a[i] += tmp;
		}
		pos = 1;
		for(int i = 1; i <= n; i++){
			if(a[pos] < a[i])pos = i;
		}
		k += tmp;
	}
	printf("%lld\n", k);
}