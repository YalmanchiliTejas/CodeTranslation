#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
typedef long long LL;
const int MaxN = 2e5;

int n;
LL a[55];
LL ans[55];
LL cnt[55];
int main()
{
	while(scanf("%d", &n) != EOF)	
	{
		for(int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		bool flag = 0;
		LL ans = 0;
		LL tot = 0;
		while(true)
		{
			flag = 0;
			tot = 0;
			for(int i = 1; i <= n; i++) {
				cnt[i] = a[i] / n;
				a[i] = a[i] % n;
				ans += cnt[i];
				tot += cnt[i];
			}
			for(int i = 1; i <= n; i++) {
				a[i] += tot - cnt[i];
				if(a[i] >= n) flag = 1;
			}
			if(flag == 0) break;
		}
		printf("%lld\n", ans);
	}
	return 0;
}