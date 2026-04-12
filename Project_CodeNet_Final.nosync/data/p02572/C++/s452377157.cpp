#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <iterator>
#include <cmath>
#include <set>
#include <deque> 
#include <string>


using namespace std;


int n;
long long a[200010];
long long rSum[200010];

const long long MOD = 1000000007;

int main()
{
	scanf("%d", &n);
	
	for (int i = 0 ; i < n ; i++)
		scanf("%lld", &(a[i]));
	
	rSum[n] = 0;
	for (int j = n - 1 ; j >= 0 ; j--) {
		rSum[j] = (rSum[j + 1] + a[j]) % MOD;
	}
	
	long long sum = 0;
	for (int i = 0 ; i < n ; i++) {
		long long prod;
		prod = (a[i] * rSum[i + 1]) % MOD;
		sum = (sum + prod) % MOD;
	}
	
	printf("%lld\n", sum);

	return 0;
}


