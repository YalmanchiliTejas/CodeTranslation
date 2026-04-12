#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

typedef long long ll;

#define rep(i,s,e) for(int i = (s);i <= (e);i++)

int n;

typedef pair<int,int> P;

vector<P> xs,ys;

struct UnionFind
{
	vector<int> par_;

	void init(int size)
	{
		par_.resize(size, 0);
		for (int i = 0; i < size; i++)
		{
			par_[i] = i;
		}
	}
	int root(int x)
	{
		return par_[x] == x ? x : par_[x] = root(par_[x]);
	}

	bool unite(int x, int y)
	{
		x = root(x);
		y = root(y);
		if (x == y)
			return true;
		par_[x] = y;
		return false;
	}
	bool same(int x, int y)
	{
		return root(x) == root(y);
	}
};

int main()
{
	cin >> n;


	for(int i = 0;i < n;i++)
	{
		int a,b;
		cin >> a >> b;

		xs.push_back(P(a,i));
		ys.push_back(P(b,i));

	}

	sort(xs.begin(),xs.end());
	sort(ys.begin(),ys.end());

	typedef pair<int,P> P2;

	priority_queue<P2,vector<P2>,greater<P2>> que;

	for(int i = 0;i < xs.size() - 1;i++)
	{
		int i1 = xs[i].second;
		int i2 = xs[i + 1].second;
		que.push(P2(xs[i + 1].first - xs[i].first,P(i1,i2)));
	}
	for(int i = 0;i < ys.size() - 1;i++)
	{
		int i1 = ys[i].second;
		int i2 = ys[i + 1].second;
		que.push(P2(ys[i + 1].first - ys[i].first,P(i1,i2)));
	}

	UnionFind uf;
	uf.init(n);

	int c = 0;
	int res = 0;
	while(c < n - 1)
	{
		P2 p = que.top();
		que.pop();

		int a = p.second.first;
		int b = p.second.second;

		if(!uf.same(a,b))
		{
			uf.unite(a,b);
			res += p.first;
			c++;
		}
	}

	cout << res << endl;
	return 0;






}
