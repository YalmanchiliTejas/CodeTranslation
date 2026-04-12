#include <cstdio>
#include <iostream>
using namespace std;

int N;
long long a[55];

int main() {
	scanf("%d",&N);
	for (int i = 1; i <= N; i++)
		scanf("%lld",a+i);
	a[0] = 0;
	long long k = 0, tmp;
	bool flag;
	do {
		flag = false;
		for (int i = 1; i <= N; i++)
			if (tmp = (a[i] - a[0]) / N) {
				flag = true;
				a[i] -= tmp * (N+1);
				a[0] -= tmp;
				k += tmp;
			}
	} while (flag);
	printf("%lld\n",k); 
	return 0;
}