#include "bits/stdc++.h"
#define MOD 1000000007
#define INF 11234567890
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

LL N;
std::vector<std::pair<std::pair<LL, LL>,LL>>xy;

// 素集合データ構造
struct UnionFind
{
	// par[i] := データ i が属する木の親の番号
	// i == par[i]のとき、データiは木の根ノード
	std::vector<LL> par;

	// sizes[i] := 根ノード i の木に含まれるデータの数
	// i が根ノードでない場合は無意味な値となる
	std::vector<LL> sizes;

	UnionFind(LL n) : par(n), sizes(n, 1)
	{
		// 最初は全てのデータ i がグループ i に存在するものとして初期化
		rep(i, n) { par[i] = i; }
	}

	// データ x が属する木の根を得る
	LL find(LL x)
	{
		if (x == par[x]) { return x; }
		return par[x] = find(par[x]);  // 根を張り替えながら再帰的に根ノードを探す
	}

	// 2つのデータ x, y が属する木をマージする
	void unite(LL x, LL y)
	{
		// データの根ノードを得る
		x = find(x);
		y = find(y);

		// 既に同じ木に属しているならマージしない
		if (x == y) { return; }

		// x の木が y の木より大きくなるようにする
		if (sizes[x] < sizes[y]) std::swap(x, y);

		// x が y の親になるように連結する
		par[y] = x;
		sizes[x] += sizes[y];
	}

	// 2つのデータ x, y が属する木が同じなら true を返す
	bool same(LL x, LL y)
	{
		return find(x) == find(y);
	}

	// データ x が含まれる木の大きさを返す
	LL size(LL x)
	{
		return sizes[find(x)];
	}
};

// 頂点 a, b をつなぐコスト cost の（無向）辺
struct Edge
{
	LL a, b, cost;

	// コストの大小で順序定義
	bool operator<(const Edge& o) const
	{
		return cost < o.cost;
	}
};

// 頂点数と辺集合の組として定義したグラフ
struct Graph
{
	LL n;					// 頂点数
	std::vector<Edge> es;	// 辺集合

	// クラスカル法で無向最小全域木のコストの和を計算する
	// グラフが非連結のときは最小全域森のコストの和となる
	LL kruskal()
	{
		// コストが小さい順にソート
		std::sort(es.begin(), es.end());

		UnionFind uf(n);
		LL min_cost = 0;

		rep(ei, es.size())
		{
			Edge& e = es[ei];
			if (!uf.same(e.a, e.b))
			{
				// 辺を追加しても閉路ができないなら、その辺を採用する
				min_cost += e.cost;
				uf.unite(e.a, e.b);
			}
		}
		return min_cost;
	}
};

// グラフの辺を張る
Graph input_graph()
{
	Graph g;
	g.n = N;
	std::sort(xy.begin(), xy.end(), [](auto&l, auto&r) {return l.first.first < r.first.first; });
	rep(i, N - 1)
	{
		Edge e;
		e.a = xy[i].second;
		e.b = xy[i + 1].second;
		e.cost = std::min(abs(xy[i].first.first - xy[i + 1].first.first), abs(xy[i].first.second - xy[i + 1].first.second));
		g.es.push_back(e);
	}
	std::sort(xy.begin(), xy.end(), [](auto&l, auto&r) {return l.first.second < r.first.second; });
	rep(i, N - 1)
	{
		Edge e;
		e.a = xy[i].second;
		e.b = xy[i + 1].second;
		e.cost = std::min(abs(xy[i].first.first - xy[i + 1].first.first), abs(xy[i].first.second - xy[i + 1].first.second));
		g.es.push_back(e);
	}
	return g;
}

int main()
{
	in >> N;
	rep(i, N)
	{
		LL x_tmp, y_tmp;
		in >> x_tmp >> y_tmp;
		xy.push_back({ { x_tmp,y_tmp }, i });
	}

	Graph g = input_graph();

	out << g.kruskal() << std::endl;
	return 0;
}