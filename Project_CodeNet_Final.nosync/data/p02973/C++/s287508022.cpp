#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;

const LL inf = 11234567890;

// RMQ
class SegmentTree
{
private:
	LL n;
	std::vector<LL>node;

public:
	void init(LL size)
	{
		n = 1;
		while (n < size) n *= 2;
		node.resize(2 * n - 1, -inf);
	}

	// node[i] = x 
	void update(LL i, LL x)
	{
		i += n - 1;
		node[i] = x;
		while (i > 0)
		{
			i = (i - 1) / 2;
			node[i] = std::max(node[2 * i + 1], node[2 * i + 2]);
		}
	}

	// min([a, b))
	// ex.) [0, N - 1] == [0, N)
	LL get_max(LL a, LL b, LL k = 0, LL l = 0, LL r = -1)
	{
		if (r < 0) r = n;
		if (r <= a || b <= l) return -inf;
		if (a <= l && r <= b) return node[k];
		LL vl = get_max(a, b, 2 * k + 1, l, (l + r) / 2);
		LL vr = get_max(a, b, 2 * k + 2, (l + r) / 2, r);
		return std::max(vl, vr);
	}
};

int main()
{
	LL N;
	in >> N;
	std::vector<LL>A(N);
	rep(i, N) in >> A[i];

	std::map<LL, std::vector<LL>>rev;
	rep(i, N) rev[A[i]].push_back(i);

	SegmentTree tree;
	tree.init(N);
	rep(i, N) tree.update(i, A[i]);

	LL max, ans = 0;
	while ((max = tree.get_max(0, N)) >= 0)
	{
		LL startNum = max;
		tree.update(rev[startNum][0], -1);
		LL end = rev[startNum][0];
		rev[startNum].erase(rev[startNum].begin());
		while (true)
		{
			tree.update(end, -1);
			if (tree.get_max(0, end) > max) break;
			max = tree.get_max(0, end);
			if (max < 0) break;
			end = rev[max][0];
			rev[max].erase(rev[max].begin());
		}
		++ans;
	}

	out << ans << std::endl;
}
