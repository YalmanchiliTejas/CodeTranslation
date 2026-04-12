#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

int H, W;
std::map<LL, bool>h, w;

int main()
{
	in >> H >> W;
	std::vector<std::vector<char>>a(H, std::vector<char>(W));
	rep(i, H) rep(j, W) in >> a[i][j];
	rep(i, H)
	{
		bool flag = false;
		rep(j, W)
		{
			if (a[i][j] == '#')
			{
				flag = true;
				break;
			}
		}
		h[i] = flag;
	}
	rep(j, W)
	{
		bool flag = false;
		rep(i, H)
		{
			if (a[i][j] == '#')
			{
				flag = true;
				break;
			}
		}
		w[j] = flag;
	}
	rep(i, H)
	{
		bool flag = false;
		rep(j, W)
		{
			if (h[i] && w[j])
			{
				flag = true;
				out << a[i][j];
			}
		}
		if (flag) out << std::endl;
	}
	return 0;
}
