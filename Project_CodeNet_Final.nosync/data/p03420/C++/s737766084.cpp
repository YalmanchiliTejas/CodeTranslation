#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <cmath>
#include <string>
#define mp make_pair
#define pb push_back

using namespace std;

int main() 
{
	int n, k;
	scanf("%d %d", &n, &k);
	long long sum = 0;
	for (int i = k+1; i<=n; ++i) {
		int a = n/i;
		int b = n%i;
		sum += (i-k)*a;
		if (b >= k)
			sum += (b-k + 1);
		if (k == 0)
			sum --;
	}
	printf("%lld", sum);
	return 0;
}