#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

LL N, ans;
std::vector<LL>s, b;

int main()
{
	in >> N;
	std::vector<LL>A(N);
	rep(i, N) in >> A[i];
	std::sort(A.begin(), A.end());
	if (N % 2 == 0)
	{
		rep(i, N / 2) s.push_back(A[i]);
		rep(i, s.size())
		{
			if (i < s.size() - 1) ans -= s[i] * 2;
			else ans -= s[i];
		}
		rep(i, N / 2) b.push_back(A[N - 1 - i]);
		rep(i, b.size())
		{
			if (i < b.size() - 1) ans += b[i] * 2;
			else ans += b[i];
		}
	}
	else
	{
		LL res1 = 0;
		rep(i, N / 2) s.push_back(A[i]);
		rep(i, s.size()) res1 -= s[i] * 2;
		rep(i, N / 2 + 1) b.push_back(A[N - 1 - i]);
		rep(i, b.size())
		{
			if (i < b.size() - 2) res1 += b[i] * 2;
			else res1 += b[i];
		}
		s.clear(); b.clear();
		LL res2 = 0;
		rep(i, N / 2 + 1) s.push_back(A[i]);
		rep(i, s.size())
		{
			if (i < s.size() - 2) res2 -= s[i] * 2;
			else res2 -= s[i];
		}
		rep(i, N / 2) b.push_back(A[N - 1 - i]);
		rep(i, b.size()) res2 += b[i] * 2;
		ans = std::max(res1, res2);
	}
	out << ans << std::endl;
	return 0;
}
