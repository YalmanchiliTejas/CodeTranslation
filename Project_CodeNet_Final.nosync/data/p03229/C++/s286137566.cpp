#include <bits/stdc++.h>
using namespace std;

#define N 100010
#define ll long long
int n;
ll arr[N], res, tmp, a, b; 
int l, r;

void work(int cnt)
{
	for (; ; cnt ^= 1)
	{
		if (l > r) return;
		if (l == r) 
		{
			tmp += max(abs(arr[l] - a), abs(arr[l] - b));
			return;
		}
		if (cnt == 0)
		{
			tmp += abs(arr[l] + arr[l + 1] - a - b);
			a = arr[l], b = arr[l + 1]; 
			l += 2;
		}
		else
		{
			tmp += abs(arr[r] + arr[r - 1] - a - b);
			a = arr[r], b = arr[r - 1];
			r -= 2;
		}
	}
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{	
		res = 0;
		for (int i = 1; i <= n; ++i) scanf("%lld", arr + i);
		if (n == 1) puts("0");
		else if (n == 2) printf("%lld\n", abs(arr[1] - arr[2]));
		else
		{
			sort(arr + 1, arr + 1 + n);
			tmp = arr[n - 1] + arr[n] - 2 * arr[1];
			a = arr[n - 1], b = arr[n];
			l = 2, r = n - 2; 	
			work(0); 
			res = max(res, tmp); 
			tmp = 2 * arr[n] - arr[1] - arr[2];
			a = arr[1], b = arr[2];
			l = 3, r = n - 1;
			work(1);
			res = max(res, tmp);
			printf("%lld\n", res);
		
		}
	}
	return 0;
}
