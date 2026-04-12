#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

#define INF 0xc0c0c0c0
#define NINF 0x3f3f3f3f

#define FOR(i, a, b) for((i)=a; i<b; ++(i))
#define EFOR(i, a, b) for((i)=a; i>b; --(i))

#define MLC(n, type) (type*)malloc(n*sizeof(type))
#define CLC(n, type) (type*)calloc(n, sizeof(type))

#define MAXN 100000+2

void solver(int *nums, int numsSize) {
	int i = 0, j = numsSize - 1;
	long long int sum1 = 0, sum2 = 0;
	sort(nums, nums+numsSize);

	for (i = 0; i+1<=j-1; ++i,--j) {
		sum1 += nums[j] + nums[j-1] - (nums[i]<<1);
		sum2 += (nums[j]<<1) - nums[i] - nums[i+1];
	}

	if (i == j) {
		sum1 = max(sum1, sum1 - nums[i] + nums[i-1] + nums[numsSize-1] - nums[i]);
		sum2 = max(sum2, sum2 - nums[j+1] + nums[i] + nums[i] - nums[0]);
	}
	else {
		sum1 += (nums[numsSize-1] - nums[i] > nums[j] - nums[i])?(nums[numsSize-1] - nums[i]):(nums[j] - nums[i]);
		sum2 += (nums[j] - nums[0] > nums[j] - nums[i])?(nums[j] - nums[0]):(nums[j] - nums[i]);
	}

	printf("%lld\n", max(sum1, sum2));
	return;
}

int main() {
	int i,n;
	int a[MAXN] = {0};

	scanf("%d", &n);

	FOR(i, 0, n) {
		scanf("%d", &a[i]);
	}

	solver(a, n);
	return 0;
}
