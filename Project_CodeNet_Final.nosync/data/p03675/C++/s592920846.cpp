#include "bits/stdc++.h"
#define MOD 1000000007
#define INF 11234567890
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;

LL n, a[212345];
std::deque<LL>ans;

int main()
{
	in >> n;
	rep(i, n) { in >> a[i]; }

	rep(i, n)
	{
		if (i % 2 == 0) { ans.push_back(a[i]); }
		else { ans.push_front(a[i]); }
	}

	if (n % 2 == 1) { std::reverse(ans.begin(), ans.end()); }
	rep(i, n - 1) { out << ans[i] << " "; }
	out << ans[n - 1] << std::endl;
	return 0;
}