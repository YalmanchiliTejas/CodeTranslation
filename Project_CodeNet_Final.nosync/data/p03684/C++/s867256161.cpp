#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;
typedef std::pair<LL, LL> P;
struct edge { LL u, v, cost; };
bool comp(const edge& e1, const edge& e2)
{
	return e1.cost < e2.cost;
}

class Union_Find
{
	std::vector<LL>per;
	std::vector<LL>rank;
public:
	void init(LL size)
	{
		rep(i, size)
		{
			per.push_back(i);
			rank.push_back(0);
		}
	}
	LL get_per(LL x)
	{
		if (x == per[x]) return x;
		return per[x] = get_per(per[x]);
	}
	bool is_same_per(LL x, LL y)
	{
		return get_per(x) == get_per(y);
	}
	void togett(LL x, LL y)
	{
		LL x_per = get_per(x), y_per = get_per(y);
		if (x_per == y_per)  return;
		if (rank[x_per] < rank[y_per]) per[x_per] = y_per;
		else
		{
			per[y_per] = x_per;
			if (rank[x_per] == rank[y_per]) ++rank[x_per];
		}
	}
};

const LL inf = 1123456789012345;
LL N;
std::vector<std::pair<LL, LL>>xp, yp;
std::vector<edge>edges;
Union_Find tree;

LL kruskal()
{
	std::sort(edges.begin(), edges.end(), comp);
	LL res = 0;
	for (auto e : edges)
	{
		if (!tree.is_same_per(e.u, e.v))
		{
			tree.togett(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}

int main()
{
	in >> N;
	std::vector<LL>x(N), y(N);
	tree.init(N + 1);
	rep(i, N)
	{
		in >> x[i] >> y[i];
		xp.push_back(std::make_pair(x[i], i + 1));
		yp.push_back(std::make_pair(y[i], i + 1));
	}
	std::sort(xp.begin(), xp.end());
	std::sort(yp.begin(), yp.end());
	rep(i, N - 1)
	{
		edges.push_back({ xp[i + 1].second,xp[i].second,xp[i + 1].first - xp[i].first });
		edges.push_back({ yp[i + 1].second,yp[i].second,yp[i + 1].first - yp[i].first });
	}
	out << kruskal() << std::endl;
	return 0;
}
