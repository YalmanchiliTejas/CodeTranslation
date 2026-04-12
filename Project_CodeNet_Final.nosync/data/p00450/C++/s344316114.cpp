#include "bits/stdc++.h"
#define MOD 1000000007
#define INF 11234567890
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

int n, c[112345];
int ans;

int main()
{
	while (true)
	{
		n = 0;
		memset(c, 0, sizeof(c));
		ans = 0;

		in >> n;
		if (n == 0) { break; }
		rep(i, n) { in >> c[i]; }

		rep(i, n)
		{
			int j;
			for (j = i + 1; j < n; ++j)
			{
				if (c[i] != c[j])
				{
					if ((j + 1) % 2 == 0)
					{
						for (int k = j - 1; k >= 0; --k)
						{
							if (c[k] == c[j]) { break; }
							c[k] = c[j];
						}
					}
					else { --j; }
					break;
				}
			}
			i = j;
		}
		rep(i, n) { ans += (c[i] == 0 ? 1 : 0); }

		out << ans << std::endl;
	}
	return 0;
}