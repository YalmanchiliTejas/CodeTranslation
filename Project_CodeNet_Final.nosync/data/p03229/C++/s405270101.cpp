#include<bits/stdc++.h>
#define N 100010
#define ll long long
using namespace std;
int n;
ll A[N];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i)
		scanf("%lld", &A[i]);
	sort(A + 1, A + n + 1);
	if(n & 1)
	{
		ll ans1 = 0, ans2 = 0;
		for(int i = 1; i <= n / 2 - 1; ++ i)
			ans1 -= 2 * A[i];
		ans1 -= A[n / 2] + A[n / 2 + 1];
		for(int i = n / 2 + 2; i <= n; ++ i)
			ans1 += 2 * A[i];
		
			
		for(int i = 1; i <= n / 2; ++ i)
			ans2 -= 2 * A[i];
		for(int i = n / 2 + 3; i <= n; ++ i)
			ans2 += 2 * A[i];
		ans2 += A[n / 2 + 1] + A[n / 2 + 2];
		printf("%lld", max(ans1, ans2));
	}
	else
	{
		ll ans = 0;
		for(int i = 1; i <= n / 2 - 1; ++ i)
			ans -= 2 * A[i];
		ans -= A[n / 2];
		for(int i = n / 2 + 2; i <= n; ++ i)
			ans += 2 * A[i];
		ans += A[n / 2 + 1];
		printf("%lld", ans);
	}
	return 0;
}