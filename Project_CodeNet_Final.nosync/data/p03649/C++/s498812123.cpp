#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int main(void){
	long long a[50];
	int c, d;
	int k;
	int n, m;
	long long x, y, z;
	long long s,t;
	long long ans;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}
	x = 0;
	y = 10000000000000030;
	for (; x != y;){
		z = (x + y) / 2;
		k = 0;
		for (int i = 0; i < n; i++){
			t = (n*z) + i;
			s = 0;
			for (int j = 0; j < n; j++){
				s = ((a[j] + t + 1) / (n+1)) + s;
			}
			if (s <= t){
				k = 1;
				break;
			}
		}
		if (k == 1)y = z;
		else x = z + 1;
	}

	for (int i = 0; i < n; i++){
		t = (n*x) + i;
		s = 0;
		for (int j = 0; j < n; j++){
			s = ((a[j] + t + 1) / (n+1)) + s;
		}
		if (s <= t){
			ans = t;
			break;
		}
	}
	printf("%lld\n", ans);

	return 0;
}
