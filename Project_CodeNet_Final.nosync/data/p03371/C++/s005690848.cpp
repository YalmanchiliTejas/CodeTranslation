#include <bits/stdc++.h>

using namespace std;

int main(void){
	long long int a, b, c, x, y;
	scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &x, &y);

	long long int mi = min(a*x + b*y, (min(x, y) * 2 * c )+ ( (max(x, y) - min(x, y)) * (max(x, y) == x ? a : b)));
	long long int mini = min((min(x, y) * 2 * c )+ ( (max(x, y) - min(x, y)) * (max(x, y) == x ? a : b)), max(x,y)*2*c);
	printf("%lld\n", min(mi, mini));
	return 0;
}