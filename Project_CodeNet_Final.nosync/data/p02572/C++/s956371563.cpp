#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

#define MOD 1000000007

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int n;
	long long cur = 0;
	long long sol = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		long long input;

		scanf("%lld", &input);

		sol = (sol + input*cur%MOD) % MOD;

		cur = (cur + input) % MOD;
	}

	printf("%lld\n", sol);

	return 0;
}