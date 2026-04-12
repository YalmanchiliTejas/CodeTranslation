#include <bits/stdc++.h>

class Solve {
private:
	using Real = long double;
	using Point = std::complex<Real>;
	using pd5 = std::array<Point, 5>;
	using vd = std::vector<Real>;
	using vvd = std::vector<vd>;

	int N, M, L;
	std::vector<pd5> stars;
	vvd graph;

	void makeStars()
	{
		stars.resize(N);
		for (auto& e: stars)
		{
			int x, y, a, r;
			scanf("%d%d%d%d", &x, &y, &a, &r);
			for (int i{}; i < 5; i++)
			{
				Real angular{(a + 90 + 72 * i) / 180.0 * M_PI};
				e[i].real(x + r * std::cos(angular));
				e[i].imag(y + r * std::sin(angular));
			}
		}
	}

	void makeGraph()
	{
		graph.resize(N, vd(N));
		for (int i{}; i < N; i++)
			for (int j{1}; j < N; j++)
				graph[i][j] = graph[j][i] = calcDistance(i, j);
	}

	Real calcDistance(int a, int b)
	{
		Real min{1e9};
		for (int a_i{}; a_i < 5; a_i++)
			for (int b_i{}; b_i < 5; b_i++)
			{
				if (linesCross(a, a_i, b, b_i))
					return 0;
				Point &a1{stars[a][a_i]}, &a2{stars[a][(a_i + 2) % 5]}, &b1{stars[b][b_i]}, &b2{stars[b][(b_i + 2) % 5]};
				min = std::min(min, std::abs(a1 - b1));
				if (std::real((a1 - b1) / (b2 - b1)) > 0 && std::real((a1 - b2) / (b1 - b2)) > 0)
					min = std::min(min, std::abs(a1 - b1) * std::abs(std::sin(std::arg((a1 - b1) / (b2 - b1)))));
				if (std::real((b1 - a1) / (a2 - a1)) > 0 && std::real((b1 - a2) / (a1 - a2)) > 0)
					min = std::min(min, std::abs(b1 - a1) * std::abs(std::sin(std::arg((b1 - a1) / (a2 - a1)))));
			}
		return min;
	}

	bool linesCross(int a, int a_i, int b, int b_i)
	{
		Point &bbase{stars[b][b_i]};
		Point &bfrom{stars[b][(b_i + 2) % 5]};
		Point &abase{stars[a][a_i]};
		Point &afrom{stars[a][(a_i + 2) % 5]};
		return std::imag((abase - bbase) / (bfrom - bbase)) * std::imag((afrom - bbase) / (bfrom - bbase)) < 0
			&& std::imag((bbase - abase) / (afrom - abase)) * std::imag((bfrom - abase) / (afrom - abase)) < 0;
	}

	Real dijkstra()
	{
		using pri = std::pair<Real, int>;
		std::priority_queue<pri, std::vector<pri>, std::greater<pri>> dij;
		dij.push({0, M});
		std::vector<Real> dist(N, 1e9);
		dist[M] = 0;
		while (!dij.empty())
		{
			auto now{dij.top()};
			dij.pop();
			if (now.first > dist[now.second]) continue;
			for (int i{}; i < N; i++)
				if (now.first + graph[now.second][i] < dist[i])
				{
					dist[i] = now.first + graph[now.second][i];
					dij.push({dist[i], i});
				}
		}
		return dist[L];
	}

public:
	bool is_last_query{};
	Solve()
	{
		scanf("%d%d%d", &N, &M, &L);
		if (N == 0)
		{
			is_last_query = true;
			return;
		}
		M--; L--;
		makeStars();
		makeGraph();
		std::cout << std::setprecision(10) << std::fixed << dijkstra() << std::endl;
	}
};

int main()
{
	while (!Solve().is_last_query);

	return 0;
}
