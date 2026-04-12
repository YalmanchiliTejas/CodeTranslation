#include <bits/stdc++.h>
using namespace std;

namespace TYC
{
	typedef long long ll;
	typedef pair<int, int> pii;

	const int N = 2e5 + 5, INF = 0x3f3f3f3f;

	int n;
	struct node { int x, y; } A[N];
	bool operator < (const node &a, const node &b) { return a.x < b.x; }

	inline int read()
	{
		int x = 0, f = 0, ch = getchar();
		while (!isdigit(ch))
			f |= (ch == '-'), ch = getchar();
		while (isdigit(ch))
			x = x * 10 + ch - '0', ch = getchar();
		return f ? -x : x;
	}

	void work()
	{
		n = read();
		int mnx = INF, mny = INF;
		int mxx = -INF, mxy = -INF;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &A[i].x, &A[i].y);
			if (A[i].x > A[i].y)
				swap(A[i].x, A[i].y);
			mnx = min(mnx, A[i].x);
			mxx = max(mxx, A[i].x);
			mny = min(mny, A[i].y);
			mxy = max(mxy, A[i].y);
		}
		ll ans = (ll)(mxx - mnx) * (mxy - mny);
		sort(A + 1, A + 1 + n);
		int t = mxy - mnx;
		mny = INF, mxy = -INF;
		for (int i = 1; i <= n; i++)
		{
			mny = min(mny, A[i].y);
			mxy = max(mxy, A[i].y);	
			ans = min(ans, (ll)t * (max(mxy, mxx) - min(mny, A[i + 1].x))); 
		}
		printf("%lld\n", ans);
	}
}

int main()
{
	TYC::work();
	return 0;
}