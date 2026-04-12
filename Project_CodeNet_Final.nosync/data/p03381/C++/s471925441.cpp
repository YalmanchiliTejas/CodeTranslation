#include <bits/stdc++.h>
using namespace std;
const int N = 200200;

#define PI acos(-1)
typedef long long ll;
#define INF 0x3f3f3f3f
int mod = 1000000007;
typedef pair<int, int> pii;
pii rec[N];
int ans[N];
int main()
{
	//freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	 // freopen("output.txt", "w", stdout);
	int n;
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			rec[i].first = x;
			rec[i].second = i;
		}
		sort(rec+1, rec + n + 1);
		int mid = (n)>>1;
		for (int i = 1; i <= n; i++)
		{
			int ix = rec[i].second;
			if (i <= mid)
				ans[ix] = rec[mid+1].first;
			else
				ans[ix] = rec[mid].first;
		}
		for (int i = 1; i <= n; i++)
			printf("%d\n", ans[i]);
	}
    return 0;
}